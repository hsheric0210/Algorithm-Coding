#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, N, M, A1[10005], A2[10005], AbsDistance[10005];
struct C { int dist, cost; };
deque<C>T;
C a, b, c;
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) cin >> A1[i];
	for (i = 0; i < N; i++) cin >> A2[i];
	for (i = 0; i < N; i++)T.push_back({ A1[i], A2[i] });
	T.push_back({ A1[N], 0x7fffffff }); // 목적지

	for (i=0;i<T.size();i++)AbsDistance[i] = (i > 0 ? AbsDistance[i - 1] : 0) + T[i].dist;

	// n = 현재 위치한 도시 #
	// k = 현재 남은 연료량\
	// a = 현재 위치한 도시
	// z = 누적 연료 비용
	a = T.front();
	k = M - T.front().dist;
	n = z = 0;
	while (true)
	{
		if (T.size() <= n + 1) break; // 중지 조건

#ifndef ONLINE_JUDGE
		cout << "BEGIN @ City #" << n << "(dist=" << a.dist << ", cost=" << a.cost << ") remain_fuel=" << k << "\n";
#endif
		// 연료단가 더 싼 도시 찾기
		// (연료단가 더 싼 도시: 연료 만땅으로 차 있다고 가정하고 앞으로 이동할 때 만나게 될 도시들 중 현재 도시의 연료단가보다 더 싼 연료단가를 가진 첫 번째 도시)
		// p = 연료단가 더 싼 도시의 연료단가
		// x = 연료단가 더 싼 도시 #
		l = 0; p = a.cost; x = -1;
		for (i = n + 1; i < T.size(); i++)
		{
			auto v = T[i];

			l += v.dist; // 해당 도시로 이동 (연료 소모)
			if (l > M) break; // 연료 만땅 상태에서 갈 수 있는 최대 거리 제한

			if (p > v.cost) // 해당 도시가 연료단가 더 싼 도시인지 검사
			{
				p = v.cost;
				x = i;
				break;
			}
		}

		// 연료 꽉 또는 일부 채워서 목적지로 바로 갈 수 있는 경우 -> 굳이 꽉 채을 필요 없음
		r = AbsDistance[T.size() - 1] - AbsDistance[n];
#ifndef ONLINE_JUDGE
		cout << "Distance to Destination: " << r << '\n';
#endif
		if (x == -1 && r <= M)
		{
			// 목적지로 바로 가기
			x = T.size() - 1;
			p = -1;
		}

		if (x > 0) // 연료단가 최적 도시 존재
		{
			q = p; // p값 백업

			// 오직 다음 최적 도시로 가기 위한 만큼만 연료 충전
			y = max(0, l - k);
			p = y * a.cost;  z += p;
#ifndef ONLINE_JUDGE
			cout << "cheap city AVAIL. dist=" << l << " min_cost=" << q << " required_fuel=" << y << " cost=(+$" << p << " = " << z << ") pos=" << x << '\n';
#endif
			k += y;


			a = T[n = x]; // 다음 최적 도시로 이동
			k -= l; // 연료 소모
			continue;
		}

		// 연료단가 최적 도시 no min avail -> full fill fuel & go to the next city

		// charge
		p = max(0, M - k) * a.cost;  z += p; // fully fill the fuel
		k = M;
#ifndef ONLINE_JUDGE
		cout << "cheap city N/A (fully fill fuel) cost=(+$" << p << " = " << z << ") next_pos=" << n + 1 << "\n";
#endif

		// move
		a = T[++n];
		k -= a.dist;
	}
	cout << z;

	return 0;
}
