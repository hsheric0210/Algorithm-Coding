/*
문제명: 자연수 나누기
교실: 고급-2
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, N;
vector<vector<int>>ok_list;
vector<int>history;
void R(int prevK, int sum)
{
	history.push_back(prevK);
	for (int k = prevK; k > 0; k--)
	{
		if (sum + k >= N) // Over or OK
		{
			if (sum + k == N) // OK
			{
				vector<int>copy = history;
				copy.push_back(k);
				ok_list.push_back(copy);
			}
			continue;
		}
		else // insufficient
		{
			R(k, sum + k);
		}
	}
	history.pop_back();
}
int main()
{
	cin >> N; R(N-1, 0);
	cout << ok_list.size() << '\n';
	for (auto h : ok_list)
	{
		for (i = 1, j = h.size(); i < j; i++) // skip first
		{
			cout << h[i];
			if (i + 1 < j)
				cout << '+';
		}
		cout << "\n";
	}
	return 0;
}