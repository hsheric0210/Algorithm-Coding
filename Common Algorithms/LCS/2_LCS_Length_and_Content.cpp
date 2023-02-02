/*
2개 문자열의 LCS 길이 구하기
https://www.acmicpc.net/problem/9252
입력: 문자열 2 줄 (최대 1000줄)
출력: LCS의 길이와 LCS 문자열
*/
#include<iostream>
#include<algorithm>
#include<deque>
#define L 1005
using namespace std;
char a[L], b[L];
int dp[L][L], i, j, u, v;
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);
	//LIS
	for (i = 0; a[i]; i++)
		for (j = 0; b[j]; j++)
			dp[i + 1][j + 1] = (a[i] == b[j]) ? (dp[i][j] + 1) : (max(dp[i + 1][j], dp[i][j + 1]));
	cout << dp[i][j] << endl;
	//Backtrack
	deque<pair<int, int>>q;
	deque<char>bt;
	q.push_back({ i, j });
	while (!q.empty())
	{
		auto top = q.back();
		q.pop_back();
		i = top.first, j = top.second;
		if (i == 0 || j == 0)
			break;
		if (a[i-1] == b[j-1]) // 구현 실수 I: 'a[i-1]와 b[j-1]'를 비교해야 하는데, 그 대신 'a[i]와 b[j]'를 비교하는 바람에 LCS의 길이는 4인데, LCS 문자열은 3개 문자인 것과 같은 문제가 발생하였다.
		{
			q.push_back({ i - 1, j - 1 });
			bt.push_front(a[i-1]); // 구현 실수 II: 'a[i-1]' 대신 'a[i]'를 푸시하는 바람에 LCS의 길이는 4인데, LCS 문자열은 3개 문자인 것과 같은 문제가 발생하였다.
		}
		else
		{
			auto a = max<tuple<int, int, int>>({
				{dp[i - 1][j], i - 1, j },
				{dp[i][j - 1], i, j - 1}
			}, [](auto a, auto b) {return get<0>(a) < get<0>(b); });
			q.push_back({ get<1>(a), get<2>(a) });
		}
	}
	if (bt.empty()) return 0;
	for (auto a = bt.begin(); a != bt.end(); a++)
		cout << *a;
	cout << endl;
}