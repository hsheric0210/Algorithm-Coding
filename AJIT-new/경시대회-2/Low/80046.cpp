/*
외계 신호 분석
https://43.200.211.173/contest/18/problem/80046
문제 오류: 백트랙하여 LCS 문자열을 출력하는 것이 아닌, LCS의 길이만 구하여 출력하면 된다.
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
#define L 105
char a[L], b[L], c[L];
int dp[L][L][L];
int i, j, k, l, m, n, o, p, q, r;
typedef struct _cmp
{
	int c, i, j, k;
} cmp;
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);
	cin.getline(c, L);

	// LCS
	for (i = 0; a[i]; i++) // SKILL: a,b,c는 null-terminated string이므로 이러한 방법으로 loop 조건을 구현할 수 있다. (null=0=false)
	{
		for (j = 0; b[j]; j++)
		{
			for (k = 0; c[k]; k++)
			{
				if (a[i] == b[j] && b[j] == c[k])
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				else
					dp[i + 1][j + 1][k + 1] = max({
						dp[i + 1][j][k], // i
						dp[i][j + 1][k], // j
						dp[i][j][k + 1], // k
						dp[i + 1][j + 1][k], // i,j
						dp[i][j + 1][k + 1], // j,k
						dp[i + 1][j][k + 1] }); // i,k
			}
		}
	}
	cout << dp[i][j][k] << endl;
}