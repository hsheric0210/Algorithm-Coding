/*
포도주 시식
https://www.acmicpc.net/problem/2156
*/
#include <iostream>
#include <algorithm>
using namespace std;
// 계단오르기(2579)와 유사한 문제
// 반례: https://www.acmicpc.net/board/view/90739
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long* a = new long long[max(n, 2)]{ 0 }; for (int i = 0; i < n; i++) cin >> a[i];
	long long* dp = new long long[max(n, 2)]{ 0 };
	/*
	dp[0] = a[0]; dp[1] = a[0] + a[1];
	dp[n] = max(
		dp[n-2], // exclude n-1
		dp[n-3] + a[n-1] // exclude n-2
	) + a[n];
	*/
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	for (int i = 2; i < n; i++) dp[i] = max(dp[i - 2], dp[i - 3] + a[i - 1]) + a[i];
	cout << *max_element(dp, dp + n) << endl;
	return 0;
}