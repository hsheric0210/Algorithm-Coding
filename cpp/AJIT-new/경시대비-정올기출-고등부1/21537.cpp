/*
야구 시즌-정올2021
https://43.200.211.173/contest/17/problem/21537
*/
#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, n, m, p, q, t, d;
int nCr(int n, int r)
{
	// Performance optimizations
	if (n == r) // nCn = 1
		return 1;
	if (r > n - r) // nCr = nCn-r
		r = n - r;
	if (r == 1) // nCn-1 = nC1 = n
		return n;

	// nPr = (n)*(n-1)*(n-2)*... -> r번 반복
	int npr = 1;
	for (j = 0; j < r; j++)
	{
		npr *= n - j;
	}

	int rfact = 1;
	for (j = 1; j <= r; j++)
		rfact *= j;
	return npr / rfact; // nPr / r! = nCr
}
int main()
{
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> n >> m >> k >> d;
		l = n * k * nCr(m, 2) + m * m * n * (n - 1) / 2;
		p = d % l;
		if (p == 0 && d / l > 0)
			cout << d << endl;
		else
		{
			d -= p;
			if (d / l > 0)
				cout << d << endl;
			else
				cout << -1 << endl;
		}
	}
}