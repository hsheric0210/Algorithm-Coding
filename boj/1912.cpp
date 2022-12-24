#include <iostream>
#include <algorithm>
using namespace std;
/*
dp[n] = max(dp[n-1] + a[n], a[n])
*/
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int* a = new int[n]; for (int i = 0; i < n; i++) cin >> a[i];

	int* dp = new int[n]{ 0 };
	dp[0] = a[0];
	for (int i = 1; i < n; i++) dp[i] = max(dp[i - 1] + a[i], a[i]);
	cout << *max_element(dp, dp + n) << endl;
	return 0;
}