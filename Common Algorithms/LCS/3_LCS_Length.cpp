/*
3개 문자열의 LCS 길이 구하기
https://www.acmicpc.net/problem/1958
입력: 문자열 3 줄 (최대 100줄)
출력: LCS의 길이
*/
#include<iostream>
#include<algorithm>
#define L 105
using namespace std;
char a[L], b[L], c[L];
int i, j, k, dp[L][L][L]; // 문자열이 3개이기에 3차원 dp
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);
	cin.getline(c, L);
	for (i = 0; a[i]; i++)
		for (j = 0; b[j]; j++)
			for (k = 0; c[k]; k++)
				dp[i + 1][j + 1][k + 1] = (a[i] == b[j] && b[j] == c[k])
				? (dp[i][j][k] + 1)
				: (max({
					dp[i + 1][j][k], // i
					dp[i][j + 1][k], // j
					dp[i][j][k + 1], // k
					dp[i + 1][j + 1][k], // i,j
					dp[i][j + 1][k + 1], // j,k
					dp[i + 1][j][k + 1] // i,k
					}));
	cout << dp[i][j][k] << endl;
}
