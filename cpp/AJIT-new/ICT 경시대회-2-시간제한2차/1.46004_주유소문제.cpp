#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, N, M, ds[10005], cci, t, TC; // ds:distance-sum; cci:current-city-index; t:current-fuel-tank TC:total-cost
struct P { int dist, cost; };
P C[10005]; // C:City
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) { cin >> j; ds[i + 1] = ds[i] + j; }
	for (i = 0; i < N; i++) { cin >> j; C[i] = { ds[i + 1] - ds[i], j }; }
	t = M; // 처음 시작 시 연료통은 꽉 찬 상태
	cci = 0; t -= C[cci].dist; // 1번 도시는 무조건 방문
	while (cci < N)
	{
		// 최적 도시 탐색 (j=최적도시index; k=최적도시와의 거리)
		for (i = cci + 1, j = -1, k = 0; i < N; i++)
		{
			k += C[i].dist;
			if (k > M) break; // 꽉 채운 연료통으로도 이 이상은 못 감; 중단
			if (C[i].cost < C[cci].cost)
			{
				j = i;
				break;
			}
		}

		// 도착점으로 한번에 뛸 수 있는지 탐색
		l = ds[N + 1] - ds[cci + 1]; // 도착지점까지와의 거리
		if (j < 0 && l < M)
		{
			j = N;
			k = l;
		}

		if (j > 0)
		{
			// 최적도시 있음 (j=최적도시index; k=최적도시와의 거리) -> 딱 최적도시로 갈 수 있을 양만 급유
			l = max(0, k - t) * C[cci].cost;
			TC += l;
			t = max(t, k);

			// 최적도시로 이동
			cci = j;
			t -= k;
			continue;
		}

		// 최적도시 없음 -> 연료통을 꽉 채우기
		l = (M - t) * C[cci].cost;
		TC += l;
		t = M;

		// 바로 다음 도시로 이동
		cci++;
		t -= C[cci].dist;
	}
	cout << TC;
	return 0;
}
