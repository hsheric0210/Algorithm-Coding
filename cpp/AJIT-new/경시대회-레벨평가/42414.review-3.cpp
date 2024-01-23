
/*
돼지 저금통
https://43.200.211.173/contest/19/problem/42414
*/
#include<iostream>
using namespace std;
int i, j, k, l, m, n, p, w, * dp;
int main()
{
	cin >> i >> j >> n;
	m = j - i;
	dp = new int[m + 1]{ 0 };
	for (i = 0; i < n; i++)
	{
		cin >> p >> w;
		if (dp[w] == 0 || dp[w] > p)
			dp[w] = p;
		for (j = w; j <= m; j++)
		{
			if (dp[j - w] == 0)
				continue;
			k = dp[j - w] + p;
			// 구현 실수 I: dp[j]를 써야 하는데 그 대신 손에 익은 dp[w]를 대신 써버림
			if (dp[j] == 0 || dp[j] > k)
				dp[j] = k;
		}
	}
	i = dp[m];
	cout << (i == 0 ? -1 : i) << endl;
}