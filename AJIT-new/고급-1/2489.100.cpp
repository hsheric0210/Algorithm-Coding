/*
문제명: 소수 구하기
교실: 고급-1
난이도: Mid
알고리즘: 에라스토테네스의 체
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <cmath>
#include <numeric>
using namespace std;

int M, N, i, j, k, l, prime[1000005];
int main()
{
	cin >> M >> N;
	// 에라스토테네스의 체
	for (i = 2, j = (int)ceil(sqrt(N)); i <= j; i++)
		if (!prime[i])
			/*
			k 초깃값이 'i+i'가 아닌 'i*i'인 이유(최적화) :
			1. i + i = i * 2 형태의 수들은 어차피 i=2 일 때 모두 걸러짐
			2. i + i + i = i * 3 형태의 수들은 어차피 i=3 일 때 모두 걸러짐
			...
			n. i + i + ... + i = i * (n-1) 형태의 수들은 어차피 i=n-1일 때 모두 걸러짐
			즉, i*2, i*3, i*4, ..., i*(i-1) 형태의 수들은 모두 이전 단계들에서 걸러져 나감 -> 검사할 필요 없음
			그렇기에 k의 초깃값은 i*i로 잡는 것임.
			*/
			for (k = i*i; k <= N; k += i)
				prime[k] = 1;
	for (i = M; i <= N; i++)
		if (i != 1 && !prime[i]) // 1은 소수가 아니라는 점에 주의
			cout << i << '\n';
	return 0;
}