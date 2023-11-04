/*
2개 문자열의 LCS 길이 구하기
https://www.acmicpc.net/problem/9252
입력: 문자열 2 줄 (최대 1000줄)
출력: LCS의 길이
*/
#include<iostream>
#define L 1005
using namespace std;
char a[L], b[L];
int i, j, dp[L][L];
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);

	for (i = 0; a[i]; i++) // SKILL: a는 null-terminated string이고, 'null=0=false'가 성립하므로 a[i]를 조건으로 사용함으로써, 'i < strlen(a)'과 같은 효과를 성능 저하 없이 얻을 수 있다.
		for (j = 0; b[j]; j++)
			dp[i + 1][j + 1] = (a[i] == b[j])
			? (dp[i][j] + 1) // 대각선 add
			: max(dp[i + 1][j], dp[i][j + 1]); // 왼쪽 또는 윗쪽 중 더 큰 값 선택
	cout << dp[i][j] << endl;
}