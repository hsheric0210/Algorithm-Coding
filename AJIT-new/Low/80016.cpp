/*
사탕 담아주기
https://43.200.211.173/contest/17/problem/80016
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, i = 0, z = 0;
double x = 0.0;
typedef struct _s // candy
{
	int a; int b; int c;
} s;
bool cm(s a, s b) { return a.a * ((double)m / a.b) < b.a * ((double)m / b.b); }
int main()
{
	cin >> n >> m;
	s* sa = new s[n];
	for (i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		sa[i] = { a,b,c };
	}
	sort(sa, sa + n, cm);
	int y = m; i = 0;
	while (y > 0)
	{
		if (z >= sa[i].c)
		{
			z = 0; i++;
		}
		if (y >= sa[i].b)
		{
			x += sa[i].a;
			y -= sa[i].b;
		}
		else if (y > 0)
		{
			x += sa[i].a * ((double)y / sa[i].b);
			y -= y;
		}
		z++;
	}
	cout << (int)ceil(x) << endl;
}