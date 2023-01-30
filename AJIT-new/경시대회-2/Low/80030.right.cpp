/*
서로 다른 소수들의 합
소스 출처: https://deefer.tistory.com/140
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int T, N, K;
int prime_size;
bool prime_check[1121];
vector<int> prime;
// dp[n][k] = n을 k개의 소수의 합으로 만들 수 있는 갯수
int dp[1121][15];

int main() {

	/* 에라토스테네스의 체 */
	int sqrt_value = (int)sqrt(1120);
	for (int i = 2; i <= sqrt_value; i++) {
		if (prime_check[i] == false) {
			for (int j = i * i; j <= 1120; j += i) {
				prime_check[j] = true;
			}
		}
	}
	for (int i = 2; i <= 1120; i++) {
		if (!prime_check[i])
			prime.push_back(i);
	}
	prime_size = prime.size();

	/* DP */
	// n을 k개로 만드는 것의 합은 dp[n-prime[i]][k-1]의 합과 같다.
	dp[0][0] = 1;
	for (int i = 0; i < prime_size; i++) {
		for (int j = 1120; j >= prime[i]; j--) {
			for (int k = 1; k <= 14; k++) {
				dp[j][k] += dp[j - prime[i]][k - 1];
			}
		}
	}

	cin >> T;
	while (T--) {
		cin >> N >> K;
		cout << dp[N][K] << '\n';
	}

	return 0;
}