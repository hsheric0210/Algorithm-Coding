#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, N, M, Dist[10005], A, B, C, D, E;
struct P { int dist, cost; };
P L[10005];
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) { cin >> j; Dist[i + 1] = Dist[i] + j; }
	for (i = 0; i < N; i++) { cin >> j; L[i] = { Dist[i + 1] - Dist[i],j }; }
	L[N] = { Dist[N + 1] - Dist[N],0x7fffffff };

	B = M; // 남은 연료
	// E: 전체 비용

	A = 0; // 시작 도시
	B -= L[A].dist;
	while (A < N)
	{
		// 최적 도시 탐색
		for (i = A + 1, j = -1, l = 0; i < N; i++)
		{
			l += L[i].dist;
			if (l > M) break;
			if (L[i].cost < L[A].cost)
			{
				j = i;
				break;
			}
		}

		if (j < 0) // 최적 도시가 없을 경우
		{
			// 끝 도시와의 거리 비교.
			if (Dist[N + 1] - Dist[A + 1] <= M)
			{
				// 끝 도시로 바로 점프 가능
				j = N;
				l = Dist[N + 1] - Dist[A + 1];
			}
		}

		if (j > 0)
		{
			E += max(0, l - B) * L[A].cost; // 비용 지불
			B = max(B, l); // 연료 충전

			B -= l; // 연료 소모
			A = j; // 이동
			continue;
		}

		E += (M - B) * L[A].cost; // 만땅으로 채울 비용 지불
		B = M; // 만땅으로 연료 충전

		A++; // 다음 도시로 이동
		B -= L[A].dist; // 연료 소모
	}

	cout << E;

	return 0;
}
