/*
관중석
https://43.200.211.173/contest/17/problem/43290
소요시간: 10시간 남짓
원인: 4연속 잘못된 접근
*/
#include<iostream>
using namespace std;
int i, j, k, l, p, q, r, d1, d2;
int chk[2005][2005];
int gc[2005][2005];
int gcd(int a, int b) // set p,q before call
{
	if (gc[a][b] == 0)
	{
		p = a, q = b;
		while (1)
		{
			r = p % q;
			if (r == 0)
			{
				gc[a][b] = q;
				break;
			}
			p = q;
			q = r;
		}
	}
	return gc[a][b];
}
int main()
{
	cin >> d1 >> d2;
	for (i = d1; i <= d2; i++)
	{
		for (j = 1; j <= i; j++)
		{
			k = gcd(i,j);
			if (!chk[i / k][j / k])
			{
				chk[i / k][j / k] = 1;
				l++;
			}
		}
	}
	cout << l << endl;
}