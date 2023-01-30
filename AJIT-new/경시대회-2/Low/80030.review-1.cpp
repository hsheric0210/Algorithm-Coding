/*
서로 다른 소수들의 합
https://43.200.211.173/contest/18/problem/80030
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int i, j, k, n, ** dp, * pchk;
vector<int> primes;
int main()
{
	// dp table init
	dp = new int* [1121];
	for (i = 0; i <= 1120; i++)
		dp[i] = new int[15]{ 0 };
	dp[0][0] = 1;

	// 구현 실수 II: pchk 초기화하는 과정을 빼먹음..
	pchk = new int[1121]{ 0 };

	// 에라스토네스의 체
	for (i = 2, n = ceil(sqrt(1120)); i <= n; i++)
		if (!pchk[i])
			for (j = i * i; j <= 1120; j += i)
				pchk[j] = 1;
	for (i = 2; i <= 1120; i++) // 구현 실수 III: 에라스토네스의 체 구현실수 - pchk[0]=pchk[1]=1로 0,1은 소수가 아님을 확실히 미리 정의하지도, i를 2로 초기화함으로써 이들 둘을 스킵하지도 않아서 1을 소수로 판정하는 일이 발생하였다.
		if (!pchk[i])
			primes.push_back(i);

	//dp
	for (i = 0, n = primes.size(); i < n; i++)
		for (j = 1120; j >= primes[i]; j--)
			for (k = 1; k <= 14; k++) // 구현 실수 I: k를 1부터 루프를 돌려야 하는데, 0부터 돌려서 인덱스 오류로 팅김 ㅋㅋ;;
				dp[j][k] += dp[j - primes[i]][k - 1];
	cin >> n >> k;
	cout << dp[n][k] << endl;
}