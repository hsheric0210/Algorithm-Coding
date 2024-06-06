#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<list>
#include<numeric>
#include<deque>
#include<iomanip>
#include<cmath>
using namespace std;
int i, j, k, l, N, A[1005];
vector<int>V;
int main()
{
	cin >> N;
	for (i = 1; i <= N; i++)cin >> A[i];
	V.push_back(0x7fffffff);
	for (i = N; i > 0; i--)
	{
		j = k = 0;
		for (auto it = V.begin(); it != V.end(); it++)
		{
			if (j == A[i])
			{
				V.insert(it, i);
				break;
			}
			if (*it > i) j++;
		}
	}
	for (auto it = V.begin(); it != V.end() - 1; it++)
		cout << *it << ' ';
	return 0;
}
// 16Ка 01УЪ
