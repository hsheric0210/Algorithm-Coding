#include<iostream>
#include<iomanip>
#include<algorithm>
#include<utility>
#include<numeric>
#include<memory>
#include<vector>
#include<list>
#include<deque>
#include<bitset>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
int i, j, k, l, N, M, ci, t, T, D[10005];
struct P { int dist, cost; };
P C[10005];
int main() // 주유소문제
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) { cin >> j; D[i + 1] = D[i] + j; }
	for (i = 0; i < N; i++) { cin >> j;  C[i] = { D[i + 1] - D[i], j }; }
	t = M - C[0].dist;
	while (ci < N)
	{
		// check optimal city
		for (i = ci + 1, j = -1, k = 0; i < N; i++)
		{
			k += C[i].dist;
			if (k > M) break;
			if (C[i].cost < C[ci].cost)
			{
				j = i;
				break;
			}
		}

		// check destination distance
		l = D[N + 1] - D[ci + 1];
		if (j < 0 && l < M)
		{
			j = N;
			k = l;
		}

		// optimal city exist
		if (j > 0)
		{
			T += max(0, k - t) * C[ci].cost;
			t = max(t, k);
			
			ci = j;
			t -= k;
			continue;
		}

		// optimal not exist
		T += (M - t) * C[ci].cost;
		t = M;
		
		ci++;
		t -= C[ci].dist;
	}
	cout << T;
	return 0;
}
// 5분 25초 34
