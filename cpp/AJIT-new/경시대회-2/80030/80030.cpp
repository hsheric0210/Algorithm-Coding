/*
서로 다른 소수들의 합
https://43.200.211.173/contest/18/problem/80030
https://deefer.tistory.com/140
https://www.acmicpc.net/problem/3908
*/
#include<iostream>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, **dp;
vector<int> primes;
int main()
{
	vector<int> primes;

	// dp테이블 heap에 할당 (StackOverflow 방지)
	dp = new int*[1121]; // n제한=1120, k제한=14
	for (i = 0; i < 1121; i++)
		dp[i] = new int[15]{0};

	// 에라스토네스의 체(?): O(n^2)
	for (i = 2; i <= 1140; i++)
	{
		int prime = 1;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				prime = 0;
				break;
			}
		}
		if (prime)
		{
			primes.push_back(i);
		}
	}

	dp[0][0] = 1;
	for (i = 0; i < primes.size(); i++) // 모든 1140 이하의 소수들에 대하여
	{

		// *** 중요 I: 1120부터 해당 소수'까지'(INCLUSIVE) 역순으로
		// 구현 실수 I: "해당 소수'까지'"라는 조건을 만족시키기 위해서는 부등호 '<='를 사용했어야 하나, 그대신 '<'를 사용하는 바람에 모든 질의에 대한 답변이 '0'으로 출력되는 문제가 발생하였다.
		for (j = 1120; j >= primes[i]; j--) 
		{
			for (k = 1; k <= 14; k++) // 각 k에 대하여
			{
				// n을 k개로 만드는 것의 합은 dp[n-prime[i]][k-1]의 합과 같다.
				// 출처: https://deefer.tistory.com/140
				dp[j][k] += dp[j - primes[i]][k - 1];
			}
		}
	}

	cin >> n >> k;
	cout << dp[n][k] << endl;
}