/*
돼지 저금통
https://43.200.211.173/contest/19/problem/42414
*/
#include<iostream>
using namespace std;
int n, m, i, j, k, l, p, w, * dp;
int main()
{
	cin >> i >> j >> n;
	m = j - i;
	dp = new int[m + 1]{0};
	for (i = 0; i < n; i++) // foreach all cases
	{
		cin >> p >> w; // read each coin price and weight
		if (dp[w] == 0 || dp[w] > p) // if dp[w] is writable
			dp[w] = p; // write initial value 'p' to dp[w]
		for (j = w; j <= m; j++) // loop: w..m
		{
			// *** 심각한 구현 실수 I: dp[j-w]가 0일 때, continue하는 조건을 빼먹음
			if (dp[j - w] == 0)
				continue;
			//

			k = dp[j - w] + p; // calculated incremented value
			if (dp[j] == 0 || dp[j] > k) // if dp[j] is (over-)writable
				dp[j] = k; // write calculated incremented value 'k' to dp[j]
		}
	}
	i = dp[m];
	cout << (i <= 0 ? -1 : i) << endl; // if dp[m] <= then -1 else dp[m] end
}