/*
관중석
https://43.200.211.173/contest/17/problem/43290
소요시간: 2시간 남짓
*/
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cmath>
#include<set>
using namespace std;
int i, j, k, l, n, p, q, d1, d2;
int cnts[2005];
int main()
{
	cin >> d1 >> d2;
	if (d1 == d2)
	{
		cout << d2 << endl;
		return 0;
	}
	for (i = 0; i <= d2; i++)
		cnts[i] = i;
	for (i = 1; i < d2; i++)
	{
		//cout << "minus " << cnts[i] << " on:" << endl;
		for (j = i + i; j <= d2; j += i)
		{
			//cout << j << endl;
			cnts[j] -= cnts[i];
		}
	}
	cout << accumulate(cnts, cnts + d2 + 1, 0) << endl;
}