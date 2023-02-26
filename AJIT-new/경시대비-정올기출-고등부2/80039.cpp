/*
햄버거 분배
https://43.200.211.173/contest/17/problem/1345
*/
#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v;
char str[20005];
int chosen[20005];
int main()
{
	cin >> n >> k;
	cin >> str;

	for (i = 0; i < n; i++)
	{
		if (str[i] == 'H') // HaMbUrGuR
		{
			for (j = min(i + k, 20000); j >= i + 1; j--)
			{
				if (str[j] == 'P')
				{
					chosen[j] = 1;
					l++;
					break;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (str[i] == 'H') // HaMbUrGuR
		{
			for (j = max(i - k, 0); j <= i - 1; j++)
			{
				if (str[j] == 'P')
				{
					chosen[j] = 1;
					m++;
					break;
				}
			}
		}
	}
	cout << "l=" << l << ", m=" << m << endl;
	cout << max(l, m) << endl;
}
