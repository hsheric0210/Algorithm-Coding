/*
문제명: 동전 바꿔주기
교실: 중급상-2
난이도: Mid
알고리즘: 2차원 Bottom-up DP
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <numeric>
#include <set>
#include <unordered_map>
#include <cstring>
using namespace std;
int T, K, P, N, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
int DP[105][10005];
int main()
{
	cin >> T >> K;
	for (i = 0; i < K; i++)
	{
		cin >> P >> N;
		for (j = 1; j <= N; j++)
			DP[i][P * j] += 1;
		if (i > 0)
		{
			for (k = 1; k < 10000; k++)
			{
				DP[i][k] += DP[i - 1][k];
				if (DP[i - 1][k] <= 0) continue;
				for (j = 1; j <= N; j++)
					DP[i][k + P * j] += DP[i-1][k];
			}
		}
	}
	
	/*for (i = 0; i < 3; i++)
	{
		for (j = 1; j < 50; j++)
		{
			cout << DP[i][j] << ' ';
		}
		cout << '\n';
	}*/

	cout << DP[K-1][T];
	return 0;
}