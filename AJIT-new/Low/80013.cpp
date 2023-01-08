/*
����
https://43.200.211.173/contest/17/problem/80011
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	//cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int l, t, n, p, i; char d; cin >> l >> t >> n;
	int* q = new int[n] {0};
	for (i = 0; i < n; i++)
	{
		cin >> p >> d;
		int e = t + p * (d == 'L' ? -1 : 1);
		auto dv = div(e, l);
		q[i] = (dv.quot % 2 == 0) ? dv.rem : l - dv.rem;
	}
	sort(q, q + n);
	for (i = 0; i < n; i++)
		cout << q[i] << ' ';
	cout.flush();
}