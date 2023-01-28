/*
소들의 시위
https://43.200.211.173/contest/19/problem/45453
*/
#include<iostream>
#define LL unsigned long long
using namespace std;
int n, m, i, j, k, l, * sum;
LL* dp;
int main()
{
	cin >> n;
	sum = new int[n + 1]{ 0 }, dp = new LL[n + 1]{0};
	dp[0] = 1;
	for (i = 1; i <= n; i++) // 구현 실수 I: 실수로 부등호를 '<=' 대신 '<'를 적는 바람에 자료 N개를 입력받는 대신 N-1개를 입력받게 되어, 항상 틀린 답만을 출력하게 됨
	{
		cin >> sum[i]; sum[i] += sum[i - 1];
	}
	for (i = 1; i <= n; i++)
		for (j = 0; j < i; j++)
			if (sum[i] >= sum[j]) // 주의: 여기 부등호 방향!
				dp[i] = (dp[i] % 1000000009 + dp[j] % 1000000009) % 1000000009;
	cout << dp[n] % 1000000009 << endl;
}