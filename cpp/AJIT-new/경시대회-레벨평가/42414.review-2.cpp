/*
돼지 저금통
https://43.200.211.173/contest/19/problem/42414
*/
#include<iostream>
using namespace std;
int i, j, k, l, m, n, o, p, * dp;
int main()
{
	cin >> i >> j >> n;
	m = j - i;
	dp = new int[m + 1]{ 0 };
	for (i = 0; i < n; i++)
	{
		cin >> k >> l;
		if (dp[l] == 0 || dp[l] > k) // if dp[l] is writable
			dp[l] = k;
		for (j = l; j <= m; j++)
		{
			if (dp[j - l] == 0) // failsafe for dp[j-1]=0
				continue;
			o = dp[j - l] + k; // calculated
			if (dp[j] == 0 || dp[j] > o) // if dp[j] is writable
				dp[j] = o;
		}
	}
	i = dp[m];
	cout << (i == 0 ? -1 : i) << endl;
}