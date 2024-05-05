#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, p, q, r, s, t, u, v, E, F, N, P, W, D[10005];
int main()
{
	cin >> E >> F >> N;
	t = E - F;
	while (N--)
	{
		cin >> P >> W;
		for (j = 1; j * W <= t; j++)
		{
			cout << j << ' ' << D[j] << ' ' << P * j << '\n';
			D[j] = max(D[j], P * j);
		}
	}

#ifndef ONLINE_JUDGE
	for (i = 0; i <= t; i++)
	{
		cout << D[i] << ' ';
	}
	cout << '\n';
#endif

	cout << D[t];

	return 0;
}
