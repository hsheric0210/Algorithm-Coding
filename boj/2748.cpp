#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long* dp = new long long[max(n, 2) + 1] {0};
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n] << endl;
	return 0;
}