/*
문제명: 동전 바꿔주기
교실: 중급상-2
난이도: Mid
알고리즘: BFS형 Bottom-up DP, 경우의 수
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
int T, K, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
int P[105], N[105];
int DP[10005];
unordered_map<int, int>VIS;
unordered_map<int, vector<int*>>COMBS;
struct comb { int T, * U; };
deque<comb>V;
int main()
{
	cin >> T >> K;
	for (i = 0; i < K; i++)
		cin >> P[i] >> N[i];

	for (i = 0; i < K; i++)
	{
		DP[P[i]]++;
		int* u = new int[105];
		memcpy(u, N, sizeof(int) * K);
		u[i]--;
		VIS[0] = 1;
		V.push_back({ P[i], u }); // push initial pivots
	}

	while (!V.empty())
	{
		auto v = V.front();
		V.pop_front();
		if (VIS[v.T])
			continue;
		for (i = 0; i < K; i++)
		{
			if (v.U[i] <= 0) continue; // Prevent unnecessary memory allocation
			int* u = new int[105];
			memcpy(u, v.U, sizeof(int) * K); // prevent previous value from getting modified
			u[i]--;
			p = v.T + P[i];
			DP[p] += DP[v.T];
			V.push_back({ p, u });
			COMBS[p].push_back(u);
			cout << "push " << p << '=' << v.T << '(' << DP[v.T] << ")+" << P[i] << " remaining->";
			for (j = 0; j < K; j++) cout << u[j] << ' ';
			cout << '\n';
		}
		VIS[v.T] = 1;
	}

	for (i = 1; i < 50; i++)
		cout << DP[i] << ' ';
	cout << '\n';

	cout << DP[T];
	return 0;
}