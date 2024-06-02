#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct C { int distance, unitCost; };
int i, j, k, l, N, M, DistanceSum[10005], TotalCost, RemainFuel, CurrentCityIndex, DistanceMovedAbsolute, DestinationDistance;
C City[10005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (i = 0; i <= N; i++) {
		cin >> j;
		DistanceSum[i + 1] = DistanceSum[i] + j;
	}
	for (i = 0; i < N; i++)
	{
		cin >> j;
		City[i] = { DistanceSum[i + 1] - DistanceSum[i], j };
	}

	City[N] = { DistanceSum[N + 1] - DistanceSum[N], 0x7FFFFFFF }; // last city
	RemainFuel = M; // 처음 출발할 때는 만땅 채우고 출발함

	// 일단 첫 번째 도시에서 시작한다고 가정하자.
	CurrentCityIndex = 0;
	RemainFuel -= (DistanceMovedAbsolute = City[CurrentCityIndex].distance);

	while (CurrentCityIndex < N)
	{
		j = -1; l = 0;

		// 연료 만땅이라고 가정했을 때 갈 수 있는 도시들 중, 현재 도시보다 연료단가 더 싼 첫 번째 도시 찾기
		for (i = CurrentCityIndex + 1; i < N; i++)
		{
			l += City[i].distance;
			if (l > M)
			{
				//cout << "City #" << (char)('A' + i) << " is not reachable with the max fuel. distance=" << l <<"; break.\n";
				break;
			}
			if (City[i].unitCost < City[CurrentCityIndex].unitCost)
			{
				j = i;
				//cout << "can jump to the optimal city: #" << (char)('A' + i) << " distance=" << l << '\n';
				break;
			}
		}

		if (j < 0 && DistanceSum[N + 1] - DistanceSum[CurrentCityIndex + 1] <= M)
		{
			// 만땅 채우면 바로 도착지점으로 갈 수 있음.
			//cout << "can jump to the end: from #" << (char)('A' + CurrentCityIndex) << " distance=" << l << '\n';
			l = DistanceSum[N + 1] - DistanceSum[CurrentCityIndex + 1];
			j = N;
		}

		// 최적 도시 존재함
		if (j > 0)
		{
			// 딱 최적 도시로 이동할 수 있을 만큼만 급유하고
			k = max(0, l - RemainFuel) * City[CurrentCityIndex].unitCost;
			RemainFuel = max(RemainFuel, l);
			//cout << "jump to optimal city: from #" << (char)('A' + CurrentCityIndex) << " to #" << (char)('A' + j) << " cost=" << k << '\n';
			TotalCost += k;
			CurrentCityIndex = j; // 최적 도시로 이동
			RemainFuel -= l;
			continue;
		}

		// 최적 도시 존재하지 않음

		// 만땅으로 채우고
		k = (M - RemainFuel) * City[CurrentCityIndex].unitCost;
		RemainFuel = M;
		//cout << "jump to next city: from #" << (char)('A' + CurrentCityIndex) << " cost=" << k << '\n';
		TotalCost += k;
		CurrentCityIndex++; // 다음 도시로 이동
		RemainFuel -= City[CurrentCityIndex].distance;
	}

	cout << TotalCost;
	return 0;
}
