#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, N, M, A1[10005], A2[10005];
struct C { int dist, cost; };
deque<C>T;
C a, b, c;
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) cin >> A1[i];
	for (i = 0; i < N; i++) cin >> A2[i];

	for (i = 0; i < N; i++)T.push_back({ A1[i], A2[i] });
	T.push_back({ A1[N], 0 });

	// n = current city index
	// k = current fuel remainder
	// a = current city
	// z = accumulative cost
	a = T.front();
	k = M - T.front().dist;
	n = z = 0;
	while (true)
	{
		if (T.size() <= n + 1) break; // oob barrier / skip the very last destination element

#ifndef ONLINE_JUDGE
		cout << "BEGIN @ City #" << n << "(d=" << a.dist << ", c=" << a.cost << ") r_fuel=" << k << "\n";
#endif
		// search the min cost
		// l = relative distance to the min city
		// x = index to the min city
		l = 0; p = a.cost; x = -1;
		for (i = n + 1; i < T.size(); i++)
		{
			auto v = T[i];
			if (l + v.dist > M) break; // max distance limit
			if (p > v.cost)
			{
				p = v.cost;
				x = i;
			}
			l += v.dist;
		}
		for (i = n + 1, l = 0; i <= x; i++)
			l += T[i].dist;

		if (x > 0) // min avail (let's go there)
		{
			q = p;//p backup
			// charge
			p = max(0, l - k) * a.cost;  z += p; // required fuel to charge
#ifndef ONLINE_JUDGE
			cout << "min AVAIL; dist=" << l << " m_cost=" << q << " r_fuel=" << l - k << " cost=(+$" << p << " = " << z << ") pos=" << x << '\n';
#endif

			// move
			a = T[n = x];

			//k = l; k -= l;
			k = 0;
			continue;
		}


		// no min avail -> full fill fuel & go to the next city

		// charge
		p = max(0, M - k) * a.cost;  z += p; // fully fill the fuel
		k = M;
#ifndef ONLINE_JUDGE
		cout << "min N/A; (full fill) cost=(+$" << p << " = " << z << ") nxt_pos=" << n + 1 << "\n";
#endif

		// move
		a = T[++n];
		k -= a.dist;
	}
	cout << z;

	return 0;
}
