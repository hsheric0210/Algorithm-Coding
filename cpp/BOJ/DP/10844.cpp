/*
쉬운 계단 수
https://www.acmicpc.net/problem/10844
*/
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long** dp = new long long* [n]{ 0 };
	for (int i = 0; i < n; i++)
		dp[i] = new long long[10]{ 0 };
	dp[0][0] = 0;
	for (int i = 1; i < 10; i++) dp[0][i] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			long long a = j < 1 ? 0 : dp[i - 1][j - 1];
			long long b = j >= 9 ? 0 : dp[i - 1][j + 1];
			dp[i][j] = (a + b) % 1000000000;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + dp[n - 1][i]) % 1000000000;
	}
	cout << sum << endl;
	return 0;
}