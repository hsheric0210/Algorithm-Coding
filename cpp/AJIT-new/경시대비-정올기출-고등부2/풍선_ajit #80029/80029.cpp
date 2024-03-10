/*
풍선_ajit
http://ajit.co.kr/contest/28/problem/80029
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define LL unsigned long long
using namespace std;
int i, j, k, l, m, n, o, p, q, r;
typedef struct _A { int i, j; } A;
int a[100005];
A b[100005];
LL t;
int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i]; b[i] = { i, a[i] }; t += a[i];
	}
	if (t <= m)
	{
		for (i = 1; i <= n; i++) cout << a[i] << ' ';
		return 0;
	}
	sort(b + 1, b + n + 1, [](A a, A b) {return a.j < b.j || a.j == b.j && a.i < b.i; });
	for (i = 1; i <= n; i = j)
	{
		p = n - i + 1; k = b[i].j - o; l = m - k * p;
		if (l >= 0)
		{
			m = l;
			o = b[i].j;
		}
		else
			break;
		for (j = i + 1; j <= n; j++)
			if (b[j].j > b[i].j)
				break;
	}

	auto d = div(m, p);
	for (i = 1; i <= n; i++)
	{
		if (a[i] <= o)
			cout << a[i] << ' ';
		else
		{
			r++;
			if (r <= d.rem)
				cout << (o + d.quot + 1) << ' ';
			else
				cout << (o + d.quot) << ' ';
		}
	}
}