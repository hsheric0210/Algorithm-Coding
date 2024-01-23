/*
소들의 시위
https://43.200.211.173/contest/19/problem/45453
*/
#include<iostream>
using namespace std;
int i, j, k, l, m, n, * sum,*dp;
int main()
{
	cin >> n;
	sum = new int[n + 1]{0};
	dp = new int[n + 1]{ 0 };
	dp[0] = 1;
	for (i = 1; i <= n; i++)
	{
		cin >> k;
		sum[i] = sum[i - 1] + k;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (sum[i] - sum[j] >= 0)
				dp[i] = (dp[i] % 1000000009 + dp[j] % 1000000009) % 1000000009;
		}
	}
	cout << dp[n] % 1000000009 << endl;
}
// 1000000009
