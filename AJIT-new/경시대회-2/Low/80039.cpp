/*
최소 횟수 에디터
https://43.200.211.173/contest/18/problem/80039
Levenshtein distance
*/
#include<iostream>
#include<algorithm>
#include<deque>
#include<tuple>
#include<vector>
#include<cstring>
#define L 1005
using namespace std;
int i, j, k, l, m, n, p, q;
char a[L], b[L];
int dp[L][L];
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);
	// 구현 실수 I: zero-index에 대한 padding 구현을 빼먹었다
	// 구현 실수 II: Edit Distance에서는 LCS에서와는 달리 for조건을 string indexing으로 설정하는 스킬 (ex: for (i=0;a[i];i++))을 사용하면 맨 마지막 원소가 설정되지 않는 문제점이 있다.
	for (i = 0, k = strlen(a); i <= k; i++)
		dp[i][0] = i;
	for (j = 0, l = strlen(b); j <= l; j++) // 구현 실수 III: strlen의 매개 변수로 b 대신 a를 넘기는 바람에 padding이 제대로 채워지지 않아 boj에서 31%에서 틀리는 문제 발생
		dp[0][j] = j;
	// 편집 거리 알고리즘
	for (i = 1, k = strlen(a); i <= k; i++) // Edit Distance에서는 
		for (j = 1, l = strlen(b); j <= l; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
		}
	cout << dp[i - 1][j - 1] << endl;
	if (dp[i - 1][j - 1] <= 0)
		return 0; // skip backtracking



	// backtracking 시 zero-index에 access하는 것을 방지하기 위한 padding 설정
	// 절대로 나올 수 없는 값을 설정함으로써 min함수가 절대로 zero-index대에 접근하지 못하도록 함
	// -> backtracking 버그 해결
	//// 구현 실수 II: 여기에 padding을 구현할 게 아니라, Edit Distance DP 실행하기 전에 먼저 zero-index에 대하여 
	//for (i = 0; a[i]; i++)
	//	dp[i][0] = 999;
	//for (j = 0; b[j]; j++)
	//	dp[0][j] = 999;



	//backtrack
	deque<pair<int, int>>q;
	deque<string>ed; // Edit Distance
	ed.push_front(b);
	q.push_back({ i - 1,j - 1 });
	while (!q.empty())
	{
		auto bk = q.back();
		q.pop_back();
		i = bk.first, j = bk.second;
		if (i == 0 && j == 0) // 구현 실수 III: '&&'로 써야 할 것을 '||'로 쓰는 바람에 어느 쪽이라도 zero가 되어 버리는 순간 loop가 종료되어 길이가 다른 두 문자열에 대한 Edit Distance Backtracking이 제대로 이루어지지 않았다.
			break;
		if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1] == b[j - 1])
		{
			q.push_back({ i - 1, j - 1 }); // no changes
		}
		else
		{
			tuple<int, int, int, int> m2[3] = {
				{ i - 1 < 0 ? 999 : dp[i - 1][j], i - 1, j, 0 }, // insert
				{ j - 1 < 0 ? 999 : dp[i][j - 1], i, j - 1, 1 }, // delete
				{ (i - 1 < 0 || j - 1 < 0) ? 999 : dp[i - 1][j - 1], i - 1, j - 1, 2 } // replace
			};
			auto m = *min_element(m2, m2 + 3, [](auto a, auto b) {return get<0>(a) < get<0>(b); });
			q.push_back({ get<1>(m), get<2>(m) });

			// simulate
			string prv = ed.front();
			switch (get<3>(m))
			{
			case 0: // insert
				prv.insert(prv.begin() + j, a[i - 1]);
				break;
			case 1: // remove
				prv.erase(prv.begin() + j - 1, prv.begin() + j);
				break;
			case 2: // replace
				prv[j - 1] = a[i - 1];
				break;
			}
			ed.push_front(prv);
		}
	}
	while (!ed.empty())
	{
		cout << ed.front() << endl;
		ed.pop_front();
	}
}