#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	int* tc = new int[t] {0};
	for (int i = 0; i < t; i++) cin >> tc[i];
	int n = *max_element(tc, tc + t);
	long long* dp = new long long[max(n, 3)]{ 0 };
	/*
	dp[0] = dp[1] = dp[2] = 1;
	dp[n] = dp[n-2] + dp[n-3]
	*/
	dp[0] = dp[1] = dp[2] = 1; for (int j = 3; j < n; j++) dp[j] = dp[j - 2] + dp[j - 3];
	for (int i = 0; i < t; i++) cout << dp[tc[i] - 1] << endl;
	return 0;
}