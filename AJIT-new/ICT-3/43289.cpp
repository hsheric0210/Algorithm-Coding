// Àú¿ï
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int i, j, k, l, N, M, x, y, p, q, r, D[2005][2005];
#define INF 12345678
int main()
{
	for (i = 0; i < 2005; i++) for (j = 0; j < 2005; j++)D[i][j] = INF;

	cin >> N >> M;
	for (i = 0; i < M; i++)
	{
		cin >> x >> y;
		D[x][y] = 1;
	}

	//FW
	for (q = 1; q <= N; q++)
		for (p = 1; p <= N; p++)
			for (r = 1; r <= N; r++)
				if (D[p][r] > D[p][q]+D[q][r])
				D[p][r] = D[p][q] + D[q][r];

	for (i = 1; i <= N; i++)
	{
		for (j = 1, k = 0; j <= N; j++)
		{
			//cout << "fw: ij-(" << i << ',' << j << ")=" << D[i][j] << ", ji-(" << j << ',' << i << ")=" << D[j][i] << '\n';
			if (i != j && D[i][j] == INF && D[j][i] == INF)
				k++;
		}
		cout << k << '\n';
	}
	return 0;
}