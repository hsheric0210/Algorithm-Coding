/*
소들의 시위
https://43.200.211.173/contest/19/problem/45453
*/
#include<iostream>
using namespace std;
int n, i, j, * sum;
long long* dp;
int main()
{
	cin >> n;
	sum = new int[n + 1]{ 0 };
	dp = new long long[n + 1]{ 0 }; // 알고리즘 구현 실수 I: (또) dp테이블 자료형 llong 대신 int형으로 하는바람에 정수 오버플로우 발발했었음
	dp[0] = 1;
	for (i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	for (i = 1; i <= n; i++)
		for (j = 0; j < i; j++)
			if (sum[i] - sum[j] >= 0) // 알고리즘 구현 실수 II: 부등호방향 반대로적음
				dp[i] = (dp[i] % 1000000009 + dp[j] % 1000000009) % 1000000009; // 알고리즘 구현실수 III: dp[i]불러올때도 나머지연산 적용해야되는데 그렇게 안 하는 바람에 정수 오버플로우가 또 발생했었음 (참고: INT_MAX = 2147483647, 나머지연산의 divisor의 2배 조금 넘음)
	cout << dp[n] % 1000000009 << endl;
}