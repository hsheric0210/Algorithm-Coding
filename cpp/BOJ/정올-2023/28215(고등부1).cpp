#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <deque>
using namespace std;

int N, K, i, j, k, l, m, n, o, p, q, r, x, y, z;
deque<pair<int,int>>pos;
int distances[55][55];
int shelters[3];

int chkdist()
{
	//cout << "check " << shelters[0] << ", " << shelters[1] << ", " << shelters[2] << '\n';
	y = 0;
	for (p = 0; p < N; p++)
	{
		x = 0x7FFFFFFF;
		for (q = 0; q < K; q++)
		{
			if (p == shelters[q])
			{
				// 대피소 집은 비교 대상에서 제외
				x = -1;
				break;
			}
			x = min(x, distances[p][shelters[q]]);
		}
		if (x < 0) continue;
		//cout << "dist between " << p << " and near shelters is " << x << '\n';
		y = max(y, x);
	}
	return y;
}

int main()
{
	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> x >> y;
		pos.push_back(make_pair(x,y));
	}

	for (i = 0; i < N; i++) for (j = 0; j < N; j++) distances[i][j] = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);

	l = 0x7FFFFFFF; // int_max
	// K 값이 최대 3이므로, 4중 for문 구성 (대피소 선택 루프 3개 + 최대 거리 최소 계산 루프 1개)
	// 시간복잡도: O(N^4 * K)
	for (i = 0; i < N; i++)
	{
		shelters[0] = i;
		for (j = 0; j < N; j++)
		{
			if (K >= 2 && i >= j) continue;
			if (K >= 2) shelters[1] = j;
			for (k = 0; k < N; k++)
			{
				if (K == 3 && (i >= k || j >= k)) continue;
				if (K == 3) shelters[2] = k;
				l = min(chkdist(), l);
				if (K <= 2) break;
			}
			if (K == 1) break;
		}
	}

	cout << l << '\n';
	return 0;
}
