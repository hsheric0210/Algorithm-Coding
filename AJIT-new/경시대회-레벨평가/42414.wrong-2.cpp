/*
돼지 저금통
https://43.200.211.173/contest/19/problem/42414
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, i, j, k, l, p, w, * dp;
int main()
{
	cin >> i >> j >> n;
	m = j - i;
	dp = new int[m + 1];
	fill(dp, dp + m + 1, 0);

	// *심각한* 구현 오류: 원래의 26164.cpp를 보고 공부하였는데, 정작 그 26164.cpp의 구현이 잘못됨.
	for (i = 0; i < n; i++)
	{
		cin >> p >> w;
		for (j = 1; j <= m; j++)
		{
			if (j % w == 0)
			{
				k = dp[j - w] + p;
				if (dp[j] <= 0 || dp[j] > k)
					dp[j] = k;
			}
		}
	}

	//for (i = 0; i <= m; i++)
	//{
	//	cout << "dp[" << i << "]=" << dp[i] << endl;
	//}

	if (dp[m] > 0) // 구현 실수 I: 다 잘 구현해놓고 여기 '만약 무게가 맞아떨어지지 않으면 -1 을 출력한다'를 검사하는 코드에서 'dp[m]>0' 조건을 'dp[n]>0'으로 잘못 적음 (사실 극초반에 n, m을 바꾸어 구현했다가 후반에 와서 이 부분을 수정하지 않아 생긴 문제임)
		cout << dp[m] << endl;
	else
		cout << -1 << endl;
}