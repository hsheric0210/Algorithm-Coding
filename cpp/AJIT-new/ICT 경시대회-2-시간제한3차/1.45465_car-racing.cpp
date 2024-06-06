#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<list>
#include<numeric>
#include<deque>
#include<iomanip>
using namespace std;
int i, j, k, l, N;
list<int>A, B;
int main()
{
	cin >> N;
	while (N--) { cin >> j; A.push_back(j); }
	k = 1;
	while (!A.empty() || !B.empty())
	{
		if (!A.empty() && A.front() == k)
		{
			A.pop_front(); k++;
		}
		else if (!B.empty() && B.front() == k)
		{
			B.pop_front(); k++;
		}
		else if (!A.empty())
		{
			B.push_back(A.front()); A.pop_front();
		}
		else
		{
			cout << "NO"; return 0;
		}
	}
	cout << "YES";
	return 0;
}
// 8Ка 11УЪ
