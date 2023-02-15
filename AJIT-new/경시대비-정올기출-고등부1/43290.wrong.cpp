/*
관중석
https://43.200.211.173/contest/17/problem/43290
소요시간: 30분 남짓
*/
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int i, j, k, l, n, d1, d2;
set<int>avail;
int main()
{
	cin >> d1 >> d2;
	for (i = d1; i <= d2; i++)
	{
		j = 2000 / i;
		for (k = 0; k <= 2000 + j /*넘어서는 것 방지*/; k += j)
		{
			if (find(avail.begin(), avail.end(), k) == avail.end())
			{
				avail.insert(k);
				l++;
			}
		}
	}
	cout << l << endl;
}