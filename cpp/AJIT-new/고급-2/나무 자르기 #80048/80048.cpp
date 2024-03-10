/*
문제명: 나무자르기 (Cutting Sticks)
교실: 고급-2
*/
#include <iostream>
#include <algorithm>
using namespace std;
int L, N, i, j, k, l, m, n, o, p, q, r, s, P[55], DP[55][55];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> L >> N;

	if (N < 2)
	{
		// no need to calculate
		cout << L;
		return 0;
	}

	P[0] = 0; P[N + 1] = L;
	for (i = 1; i <= N; i++) cin >> P[i];

	for (i = 2; i <= N + 1; i++)
	{
		for (j = 0; j <= N + 1 - i; j++)
		{
			auto M = 0x7FFFFFFF;
			for (k = j + 1; k < j + i; k++)
				M = min(M, DP[j][k] + DP[k][j + i]);
			DP[j][j + i] = P[j + i] - P[j] + M;
		}
	}

#ifndef ONLINE_JUDGE
	for (i = 0; i <= N + 1; i++)
	{
		for (j = 0; j <= N + 1; j++)
		{
			cout << DP[i][j] << ' ';
		}
		cout << '\n';
	}
#endif

	cout << DP[0][N + 1];
	return 0;
}
