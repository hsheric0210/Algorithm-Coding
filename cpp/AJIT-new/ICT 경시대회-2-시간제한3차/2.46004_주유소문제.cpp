#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<list>
#include<numeric>
#include<deque>
#include<iomanip>
#include<cmath>
using namespace std;
int i, j, k, l, N, M, ci, t, T, D[10005]; // ci:currentCityIndex, t:currentFuelTank, T:totalCost, D:distanceSumArray
struct Z { int dist, cost; };
Z C[10005]; // C:Cities
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) { cin >> j; D[i + 1] = D[i] + j; }
	for (i = 0; i < N; i++) { cin >> j; C[i] = { D[i + 1] - D[i],j }; }
	t = M - C[0].dist; // 첫 번째 도시는 항상 간다
	while (ci < N)
	{
		// 최적도시탐색 (j=최적도시거리, k=최적도시index)
		for (i = ci + 1, j = 0, k = -1; i < N; i++)
		{
			j += C[i].dist;
			if (j > M) break;
			if (C[i].cost < C[ci].cost)
			{
				k = i;
				break;
			}
		}

		// 도착점과의 거리 검사
		l = D[N + 1] - D[ci + 1];
		if (k < 0 && l < M)
		{
			k = N;
			j = l;
		}

		// 최적도시가 존재
		if (k > 0)
		{
			// 딱 필요한 만큼만 급유
			l = max(0, j-t) * C[ci].cost;
			T += l;
			t = max(t, j);

			// 최적도시로 이동
			ci = k;
			t -= j;
			continue;
		}

		// 최적도시가 없음

		// 만땅으로 급유
		l = (M - t) * C[ci].cost;
		T += l;
		t = M;

		// 바로 다음 도시로 이동
		ci++;
		t -= C[ci].dist;
	}
	cout << T;
	return 0;
}
// 12분 39초
