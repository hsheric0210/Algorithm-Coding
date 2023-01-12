/*
소들의 시위 (***)
https://43.200.211.173/contest/17/problem/80022
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, j;
int main()
{
	cin >> n;
	int* arr = new int[n + 1]{ 0 };
	int* sum = new int[n + 1]{ 0 };
	long long* dp = new long long[n + 1]{ 0 };
	dp[0] = 1;
	for (i = 1; i <= n; i++) cin >> arr[i];
	for (i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
	for (i = 1; i <= n; i++) for (j = 0; j < i; j++) if (sum[i] - sum[j] >= 0) dp[i] = (dp[i] + dp[j]) % 1000000009;
	cout << *max_element(dp + 1, dp + n + 1) % 1000000009 << endl;
}
