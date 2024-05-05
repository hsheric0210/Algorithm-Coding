#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, p, q, r, s, t, u, v, E, F, N, P, W, D[10005];
int main()
{
	cin >> E >> F >> N; F -= E;
	while (N--)
	{
		cin >> P >> W;
		if (D[W] == 0 || D[W] > P) D[W] = P; // initial
		for (j = W; j <= F; j++) // gr33dy
		{
			if (D[j - W] <= 0) continue;
			k = D[j - W] + P;
			if (!D[j] || D[j] > k)
				D[j] = k;
		}
	}

	cout << (D[F] == 0 ? -1 : D[F]);
	return 0;
}
