/*
점프(정올2019)
https://43.200.211.173/contest/17/problem/17507
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
int a[32], b[32];
void build()
{
	b[1] = 1;
	for (i = 1; i < 31; i++)
	{
		a[i] = (int)pow(2, i) - 1;
		if (i > 1)
			b[i] = b[i - 1] + (i - 1);
	}
}
int func(int n, int depth)
{
	if (n == 0) return depth;
	auto lb = lower_bound(a, a + 30, n);
	if (*lb != n)
		lb--;
	return func(n - (*lb), depth + (lb - a));
}
int main()
{
	build();
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> x >> y;
		if (x == y)
		{
			cout << func(y, 0) << endl;
		}
		else
		{
			auto lb = lower_bound(a, a + 31, y);
			if (*lb == y)
			{
				cout << lb - a << endl;
			}
			else if (*lb == y + 1)
			{
				cout << b[lb - a] << endl;
			}
			else
			{
				l = 0;
				cout << "a[i] = " << a[lb - a] << ", a[i-1]=" << a[lb - a - 1] << endl;
				cout << "b[i] = " << b[lb - a] << ", b[i-1]=" << b[lb - a - 1] << endl;
				cout << "from " << a[lb - a - 1] + 1 << " to " << y << " -> distance " << y - (a[lb - a - 1] + 1) << endl;
				for (p = a[lb - a - 1] + 1; p <= y; p++)
				{
					q = func(p, 0);
					if (q > l)
						l = q;
				}
				cout << max(b[lb - a - 1], l) << endl;
			}
		}
	}
}