// Olympiad > 한국정보올림피아드 > 한국정보올림피아드시․도지역본선 > 지역본선 2013 > 고등부 2번
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int K, N, i, j, k, l, m, n, o, p, q, r, s, P[50][50];
int main(int argc, char** argv) {
	cin >> K >> N;

	// init table
	for (i = 0; i <= K; i++)
		for (j = 0; j <= K; j++)
		{
			if (i == j || i == j + 1) P[i][j] = 0;
			else if (i + 1 == j) P[i][j] = 1;
			else P[i][j] = 1e8;
		}

	// read
	for (i = 0; i < N; i++)
	{
		cin >> p >> q >> r;
		// // // // // // // // // //
		if (P[p - 1][q] > r) // Without this branch, it will fail on 85%
		// // // // // // // // // //
			P[p - 1][q] = r;
		P[q][p - 1] = -r;
	}

	// floyd-warshall
	for (j = 0; j <= K; j++)
		for (i = 0; i <= K; i++)
			for (k = 0; k <= K; k++)
				P[i][k] = min(P[i][k], P[i][j] + P[j][k]);

#ifndef ONLINE_JUDGE // see https://help.acmicpc.net/language/info
	// dump table
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < K; j++)
		{
			cout << setw(8) << P[i][j] << ' ';
		}
		cout << '\n';
	}
#endif

	// check cycle
	for (i = 0; i <= K; i++) if (P[i][i] < 0)
	{
		cout << "NONE";
		return 0;
	}

	for (i = 0; i < K; i++)
		cout << (P[0][i + 1] - P[0][i] ? '#' : '-');
	return 0;
}