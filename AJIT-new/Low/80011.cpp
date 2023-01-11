/*
°³¹Ì
https://43.200.211.173/contest/17/problem/80011
*/
#include <iostream>
#include <algorithm>
using namespace std;
int l, t, n, p, i, e;
char d;
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> t >> n;
	int* q = new int[n] {0};
	for (i = 0; i < n; i++)
	{
		cin >> p >> d;
		e = t + p * (d == 'L' ? -1 : 1);
		auto dv = div(e, l);
		q[i] = (dv.quot % 2 == 0) ? dv.rem : l - dv.rem;
		if (q[i] < 0) q[i] = -q[i];
	}
	sort(q, q + n);
	for (i = 0; i < n; i++)
		cout << q[i] << ' ';
	cout.flush();
}