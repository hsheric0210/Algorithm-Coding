/*
공주님의 정원
https://43.200.211.173/contest/17/problem/2996
C-Minifier friendly version
*/
#include <iostream>
#include <algorithm>
using namespace std;
int ml[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
typedef struct _xy
{
	int x; int y;
} xy;
int dc(int m, int d)
{
	int t = 0;
	for (int i = 0; i < m - 1; i++) t += ml[i];
	t += d;
	return t;
}
int bc(xy a, xy b) { return a.x < b.x; }
int ec(xy a, xy b) { return a.y > b.y; }
int main()
{
	int n, mm, md, Mm, Md, i, cnt = 1, x = -1, xi = -1; cin >> n;
	int m1 = dc(3, 1), n30 = dc(11, 30);
	xy* a1 = new xy[n];
	xy* a2 = new xy[n];
	for (i = 0; i < n; i++)
	{
		cin >> mm >> md >> Mm >> Md;
		a1[i] = a2[i] = { dc(mm, md), dc(Mm, Md) };
	}
	sort(a1, a1 + n, bc);
	sort(a2, a2 + n, ec);
	for (i = 0; i < n; i++)
	{
		if (a1[i].x > m1)
			break;
		if (a1[i].y > x)
		{
			x = a1[i].y;
			xi = i;
		}
	}
	while (true)
	{
		if (x > n30)
			break;
		int pmx = x, _xi = 0;
		x = 0;
		for (int i = xi + 1; i < n; i++)
		{
			if (a1[i].x >= pmx + 1)
				break;
			if (a1[i].y > x)
			{
				x = a1[i].y;
				_xi = i;
				if (x > n30)
					break;
			}
		}
		if (x == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		xi = _xi;
		cnt++;
	}
	cout << cnt << endl;
}