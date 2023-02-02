/*
3개 문자열의 LCS 길이 구하기
https://www.acmicpc.net/problem/1958
입력: 문자열 3 줄 (최대 100줄)
출력: LCS의 길이와 LCS 문자열
*/
#include<iostream>
#include<algorithm>
#include<deque>
#define L 105
using namespace std;
int i, j, k, dp[L][L][L];
char a[L], b[L], c[L];
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);
	cin.getline(c, L);
	for (i = 0; a[i]; i++)
		for (j = 0; b[j]; j++)
			for (k = 0; c[k]; k++)
				dp[i + 1][j + 1][k + 1] = (a[i] == b[j] && b[j] == c[k]) ? (dp[i][j][k] + 1) : (max({ dp[i + 1][j][k], dp[i][j + 1][k], dp[i][j][k + 1], dp[i + 1][j + 1][k], dp[i][j + 1][k + 1], dp[i + 1][j][k + 1] }));
	cout << dp[i][j][k] << endl;
	deque<tuple<int, int, int>>q;
	deque<char>lcs;
	q.push_back({ i,j,k });
	while (!q.empty())
	{
		auto &top = q.back();
		q.pop_back();
		i = get<0>(top), j = get<1>(top), k = get<2>(top);
		if (i == 0 || j == 0 || k == 0)
			break; // 구현 실수 I: 루프 종료 조건 빼먹어서 negative index error로 런타임 에러
		if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
		{
			q.push_back({ i - 1,j - 1,k - 1 });
			lcs.push_front(a[i - 1]);
		}
		else
		{
			auto a = max<tuple<int, int, int, int>>({
				{dp[i - 1][j][k], i - 1, j, k},
				{dp[i][j - 1][k], i, j - 1, k},
				{dp[i][j][k - 1], i, j, k - 1},
				{dp[i - 1][j - 1][k], i - 1, j - 1, k},
				{dp[i][j - 1][k - 1], i, j - 1, k - 1},
				{dp[i - 1][j][k - 1], i - 1, j, k - 1}
				}, [](auto a, auto b) {return get<0>(a) < get<0>(b); });
			q.push_back({ get<1>(a), get<2>(a), get<3>(a) });
		}
	}
	if (lcs.empty())
		return 0;
	for (auto a = lcs.begin(); a != lcs.end(); a++)
		cout << *a;
	cout << endl;
}