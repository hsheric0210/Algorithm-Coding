/*
Wagner–Fischer algorithm
Levenshtein distance
Addition, Deletion, Substitution 지원
*/
//#define DP_DUMP
#include<iostream>
#include<algorithm>
#include<cstring>
#ifdef DP_DUMP
#include<iomanip>
#endif // DP_DUMP
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

	// 중요! : LD 알고리즘 구현에서 절대로 아래의 zero-index element들에 대한 padding 구현 빼먹으면 안된다!
	for (i = 0; i <= k; i++)
		dp[i][0] = i;
	for (j = 0; j <= l; j++)
		dp[0][j] = j;

	// dp
	for (i = 1; i <= k; i++)
		for (j = 1; j <= l; j++)
			// 구현 실수 I: min 대신 max씀
			dp[i][j] = (a[i - 1] == b[j - 1]) ? (dp[i - 1][j - 1]) : (min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1);
#ifdef  DP_DUMP
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j <= l; j++)
			cout << setw(2) << dp[i][j] << ' ';
		cout << endl;
	}
#endif //  DP_DUMP
	cout << dp[k][l] << endl;
}