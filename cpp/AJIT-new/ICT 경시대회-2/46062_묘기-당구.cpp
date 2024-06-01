#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;
int i, j, k, l, P, Q, m, n, o, r, s, t, u, v, w, x, y, z;
vector<int>Trace;
int gcd(int a, int b) { int c; while (1) { c = a % b; if (c == 0)return b; a = b; b = c; }	return 1; }// ��Ŭ���� ȣ����
int corner() { return (P % 2) ? (4 - Q % 2) : (1 + Q % 2); }
int main()
{
	cin >> P >> Q; // slope: P/Q
	k = gcd(P, Q); P /= k; Q /= k; // ���
	u = min(P, Q); v = max(P, Q);
	if (P != Q)
	{
		for (i = 1, j = 0; i <= u; i++)
		{
			auto dv = div(i * v, u); if (dv.rem == 0)dv.quot--; k = dv.quot - j; // delta
			j = dv.quot;
			m = j % 2;

			for (x = 1; x <= k; x++)
				Trace.push_back(m = (m + 1) % 2); // ����: 0=E, 1=W, ����: 0=N, 1=S
			reverse(Trace.end() - k, Trace.end());

			if (dv.rem)
				Trace.push_back((y = (y + 1) % 2) + 2); // ����: 2=S, 3=N, ����: 2=W, 3=E
		}
	}

	cout << Trace.size() << '\n';
	z = P > Q;
	for (int v : Trace)
		switch (v)
		{
			case 0:cout << (z ? 'N' : 'E') << ' '; break;
			case 1:cout << (z ? 'S' : 'W') << ' '; break;
			case 2:cout << (z ? 'W' : 'S') << ' '; break;
			case 3:cout << (z ? 'E' : 'N') << ' '; break;
		}
	cout << corner();
	return 0;
}
