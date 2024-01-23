/*
소들의 시위
https://43.200.211.173/contest/19/problem/45453

- dp테이블의 자료형을 long long으로 시도하니 성공한 것을 보면, dp테이블 계산의 모든 부분에 전부 나머지연산을 작용해야 하는 것 같다.
*/
#include<iostream>
using namespace std;
int n, m, i, j, k, l, * sum, * dp;
int main()
{
	cin >> n;
	sum = new int[n + 1]{ 0 };
	dp = new int[n + 1]{ 0 };
	dp[0] = 1;
	for (i = 1; i <= n; i++)
	{
		cin >> l;
		sum[i] = sum[i - 1] + l;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (sum[i] - sum[j] >= 0) // 구현 실수 I: 이 부분을 'sum[i] - sum[j]' 대신 'sum[j] + arr[i]' 로 짜는 바람에 제대로 된 구현에 실패했었음
				dp[i] = (dp[i] + dp[j] % 1000000009) % 1000000009;
		}
	}

	cout << dp[n] % 1000000009 << endl; // 구현 실수 II: 대충대충 구현하다가 실수로 1000000009로 안 나누고 그대로 출력해 버렸었음
}

/*
arr=0 2 3 -3 1

sum=0 2 5 2 3
dpt=1 1 2 2 4
-> dpt[4] = 4 ok
*/