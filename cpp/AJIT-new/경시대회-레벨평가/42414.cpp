/*
돼지 저금통
https://43.200.211.173/contest/19/problem/42414
*/
#include<iostream>
#include<algorithm>
int n, m, i, j, k, l, p, w, * dp;
using namespace std;
int main()
{
	cin >> i >> j >> n;
	m = j - i;
	dp = new int[m + 1]{ 0 };
	for (i = 0; i < n; i++)
	{
		cin >> p >> w;
		if (dp[w] == 0 || dp[w] > p) // dp[w]를 업데이트할 수 있다면
			dp[w] = p; // dp[w]에 초깃값을 넣는다

		// 굳이 dp[w]를 먼저 설정하고 나서 w부터 보기 시작하는 이유:
		//  어차피 j의 값이 w이기 전까지는 j-w가 항상 음수이기에, 굳이 볼 필요가 없기 때문
		for (j = w; j <= m; j++)
		{
			if (dp[j - w] == 0) // dp[j-w]가 0이면 
				continue;
			k = dp[j - w] + p; // 계산된 값
			if (dp[j] == 0 || dp[j] > k) // 만약 dp[j]에 값을 업데이트할 수 있다면: dp[j]가 비어 있거나(0) or 계산된 값(k)가 dp[j]보다 작다면
				dp[j] = k;
		}
	}
	i = dp[m];
	cout << (i <= 0 ? -1 : i) << endl;
}