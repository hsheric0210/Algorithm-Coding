/*
Wagner–Fischer algorithm
Levenshtein distance
Addition, Deletion, Substitution 지원
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define L 1005
using namespace std;
int i, j, k, l;
char a[L], b[L];
int dp[L][L];
int main()
{
	cin.getline(a, L);
	cin.getline(b, L);
	k = strlen(a), l = strlen(b);
	for (i = 0; i <= k; i++)
		dp[i][0] = i;
	for (j = 0; j <= l; j++)
		dp[0][j] = j;
	for (i = 1; i <= k; i++)
		for (j = 1; j <= l; j++)
			// 구현 실수 I: substitute를 제외한 나머지 add, remove에 대하여 +1를 해주는 것을 잊었다
			// 구현 실수 II: substitute cost의 add조건 검사 비교 연산자를 '!=' 대신 '=='로 적는 실수를 저질렀다
			// 구현 실수 III: wikipedia의 구현만 그대로 따라 보고 하다가 input string과 target string이 zero-offset인지 one-offset인지를 구분하지 않고 그대로 a[i] != b[j]로 바로 엑세스해버리는 실수를 저질렀다
			dp[i][j] = min({ dp[i - 1][j - 1] + (a[i-1] != b[j-1]), dp[i - 1][j] + 1, dp[i][j - 1] + 1 }); 
	cout << dp[k][l] << endl;
}