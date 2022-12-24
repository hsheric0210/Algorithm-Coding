#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int c = max(n, 2) * 2;
	int* dp = new int[c + 1] {0};
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 2; i <= c; i++)
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
	cout << dp[n+1] % 10007 << endl;
	return 0;
}