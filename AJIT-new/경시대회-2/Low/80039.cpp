/*
최소 횟수 에디터
https://43.200.211.173/contest/18/problem/80039
*/
#include<iostream>
#include<algorithm>
#include<deque>
#define L 1005
using namespace std;
int i, j, k, l, m, n, p, q;
char a[L], b[L];
int dp[L][L];
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);
	// 편집 거리 알고리즘
	for (i = 0; a[i]; i++)
		for (j = 0; b[j]; j++)
			dp[i + 1][j + 1] = (a[i] == b[j]) ? (dp[i][j]) : (min({ dp[i][j], dp[i + 1][j], dp[i][j + 1] }) + 1);
	cout << dp[i][j] << endl;
	//backtrack
	deque<pair<int, int>>q;
	deque<char>ed; // Edit Distance
	q.push_back({i,j});
	while (!q.empty())
	{
		auto bk = q.back();
		q.pop_back();
		i = bk.first, j = bk.second;
		if (i == 0 || j == 0)
			break;
		if (a[i - 1] == b[j - 1])
		{
			q.push_back({i-1, j-1});
		}
		else
		{
			auto a = min<tuple<int, int, int, int>>({
				{dp[i-1][j-1], i-1, j-1, 0}, // modify
				{dp[i-1][j], i-1, j, 1}, // add
				{dp[i][j-1],i,j-1, 2} // delete
			}, [](auto a, auto b) {return get<0>(a) < get<0>(b); });
			q.push_back({ get<1>(a), get<2>(a) });
			cout << get<3>(a) << endl;
		}
	}
}