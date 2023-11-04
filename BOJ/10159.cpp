/*
문제명: 저울
알고리즘: Floyd-warshall
*/
#include <iostream>
using namespace std;
int N,M,i, j, k, l, m, n, o, p, q, r, F[105][105];
int main()
{
	cin >> N >> M;
	for (i = 0; i < M; i++)
	{
		cin >> p >> q; // 무게는 p > q 이다
		F[p][q] = 1;
	}

	for (j = 1; j <= N; j++)
		for (i = 1; i <= N; i++)
			for (k = 1; k <= N; k++)
				if (F[i][j] && F[j][k])
				{
					F[i][k] = 1;
				}
	for (i = 1; i <= N; i++)
	{
		k = ;
		for (j = 1; j <= N; j++)
		{
			if (!F[i][j] && !F[j][i])
				k++;
		}
		cout << k << '\n';
	}
	return 0;
}