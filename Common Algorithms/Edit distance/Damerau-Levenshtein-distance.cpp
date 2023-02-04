/*
Damerau-Levenshtein distance
Addition, Deletion, Substitution, Transposition ����
*/


// FIXME: BOJ https://www.acmicpc.net/problem/15484���� 2�� ���� ����

#define DP_DUMP
#include<iostream>
#include<algorithm>
#include<cstring>
#ifdef DP_DUMP
#include <iomanip>
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
	for (i = 0; i <= k; i++)
		dp[i][0] = i;
	for (j = 0; j <= l; j++)
		dp[0][j] = j;
	for (i = 1; i <= k; i++)
		for (j = 1; j <= l; j++)
		{
			// default LD
			dp[i][j] = min({ dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]), dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
			// ���� �Ǽ� I: transpose ���� ������ 'a[i-1]==b[j-2] and a[i-2]==b[j-1]'�� �ؾ� �ϴµ� �״�� 'a[i-1]==b[i-2] and a[i-2]==b[i-1]' �� j�� ���� �� b-access ������ ���δ� i���� ����� ���ȴ�.
			if (i - 2 >= 0 && j - 2 >= 0 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1]) // transposition available
				dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + 1);
		}
#ifdef DP_DUMP
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j <= l; j++)
			cout << setw(3) << dp[i][j] << ' ';
		cout << endl;
	}
#endif // DP_DUMP
	cout << dp[k][l] << endl;
}