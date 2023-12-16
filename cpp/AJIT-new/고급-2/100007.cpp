/*
문제명: 영합 구하기
교실: 고급-2
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, i, j, k, l, m, n, o, p, q, r;
unsigned long long a, b, c, DP[1280][50];
int main()
{
	cin >> N >> M;
	p = ((M * (M + 1) / 2) - (N * (N - 1) / 2));
	if (p % 2 != 0) // 2로 안 나누어떨어지면 절대로 못 만듦 (다 합해서 p/2가 되는 경우를 구해야 하기 때문)
	{
		cout << 0;
		return 0;
	}

	DP[N][N] = 1;
	for (i = 1; i <= N; i++) k += i; // k = sum(1, 2, ..., N)
	for (i = N+1; i <= M; i++) // 다 더해서 p/2 가 나오는 경우를 모두 찾기
	{
		k += i; // sum
		// scan (i+1)..(sum(1, 2, ..., i))
		for (j = i + 1; j <= k; j++)
		{
			for (l = 1, a = 0; l < i; l++)
				a += DP[j - i][l];
			DP[j][i] = a;
		}
	}

#ifndef ONLINE_JUDGE
	cout << "p=" << p << " (target=" << p / 2 << ")\n";
	for (i = 1; i <= p / 2; i++)
	{
		for (j = 1; j <= M; j++)
			cout << DP[i][j] << ' ';
		cout << '\n';
	}
#endif

	for (a = 0, i = 0; i <= M; i++)
		a += DP[p / 2][i];
	cout << a;
	return 0;
}