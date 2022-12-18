#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>

/*
f(n) = 'n번째 계단을 밟으면서, 얻을 수 있는 점수의 최댓값'

f(n) = max(f(n-1), f(n-2))
*/

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int* stairs = new int[n + 1]();
	memset(stairs, 0, sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];

	int* dp = new int[n + 1]();
	dp[0] = 0;
	dp[1] = stairs[1];
	int increment = 1;
	for (int i = 2; i <= n; i++)
	{
		int m;
		if (++increment >= 3) // 연속된 세 개의 계단 밟는 경우 방지
		{
			m = dp[i - 2];
			increment = 0;
			cout << "i=" << i << " dp[i] = dp[i-2](= " << dp[i - 2] << ") + stairs[i](= " << stairs[i] << ")" << endl;
		}
		else
		{
			m = max(dp[i - 1], dp[i - 2]);
			cout << "i=" << i << " dp[i] = dp[i-1](= " << dp[i - 1] << ") or dp[i-2](= " << dp[i - 2] << ") + stairs[i](= " << stairs[i] << ")" << endl;
		}
		dp[i] = m + stairs[i];
	}

	cout << dp[n] << endl;

	delete[] stairs;
}