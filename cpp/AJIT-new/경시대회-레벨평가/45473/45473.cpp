/*
서로 다른 소수들의 합
https://43.200.211.173/contest/19/problem/45473
*/
#include<iostream>
#include<cmath>
using namespace std;
int i, j, k, l, n, * chk, ** dp;
int main()
{
	chk = new int[1121]{ 0 };
	dp = new int* [1121];
	for (i = 0; i <= 1120; i++)
		dp[i] = new int[15]{ 0 };
	dp[0][0] = 1;
	for (i = 2, n = sqrt(1120); i <= n; i++)
		if (!chk[i])
			for (j = i * i; j <= 1120; j += i)
				chk[j] = 1;
	for (i = 2; i <= 1120; i++)
		if (!chk[i])
			for (j = 1120; j >= i; j--)
				for (k = 1; k <= 14; k++)
					dp[j][k] += dp[j - i][k - 1];
	cin >> n >> k;
	cout << dp[n][k] << endl;
}