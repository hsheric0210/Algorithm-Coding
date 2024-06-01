#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, N, M, A1[10005], A2[10005], D[10005];
struct C { int dist, cost; };
vector<C>T;
C a, b, c;
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) cin >> A1[i];
	for (i = 0; i < N; i++) cin >> A2[i];
	for (i = 0; i < N; i++)T.push_back({ A1[i], A2[i] });
	T.push_back({ A1[N], 0x7fffffff });
	for (i=0;i<T.size();i++)D[i] = (i > 0 ? D[i - 1] : 0) + T[i].dist;
	a = T.front();
	k = M - T.front().dist;
	n = z = 0;
	while (true)
	{
		if (T.size() <= n + 1)break;
		l = 0; p = a.cost; x = -1;
		for (i = n + 1; i < T.size(); i++)
		{
			auto v = T[i];
			l += v.dist;
			if (l > M) break;
			if (p > v.cost){ p = v.cost; x = i; break; }
		}
		r = D[T.size() - 1] - D[n];
		if (x == -1 && r <= M){ x = T.size() - 1; p = -1; }
		if (x > 0)
		{
			y = max(0, l - k);
			p = y * a.cost;  z += p;
			k += y;
			a = T[n = x];
			k -= l;
			continue;
		}
		p = max(0, M - k) * a.cost;  z += p;
		k = M;
		a = T[++n];
		k -= a.dist;
	}
	cout << z;
	return 0;
}
