/*
숫자카드
https://43.200.211.173/contest/18/problem/3130
*/
#include <iostream>
#include <cstring>
using namespace std;
char s[45];
int n[45];
int* dp;
int l, i;
int main()
{
	cin.getline(s, 45); l = strlen(s);
	for (i = 0; i < l; i++) n[i + 1] = s[i] - '0';
	dp = new int[l + 1]{ 1 };
	for (i = 1; i <= l; i++) dp[i] = (n[i] != 0 ? dp[i - 1] : 0) + ((i - 2 >= 0 && n[i - 1] != 0 && n[i - 1] * 10 + n[i] <= 34) ? dp[i - 2] : 0);
	cout << dp[l] << endl;
}
