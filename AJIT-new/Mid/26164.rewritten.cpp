/*
돼지 저금통
https://43.200.211.173/contest/17/problem/26164

틀린 사유: 선생님의 알고리즘 설명 자체를 잘못 이해하여 잘못 구현함
	-> DBG 활성화하고 원본 소스와 rewritten 소스의 디버그 출력만 봐도 알 수 있음
*/
#include <iostream>
#include <algorithm>
using namespace std;
//#define DBG
int main()
{
	int e, f, n; cin >> e >> f >> n; f -= e; // f: 총 동전 무게
	int dpsz = max(2, f + 1);
	int* dp = new int[dpsz];
	fill(dp, dp + dpsz, 0);
	for (int i = 0; i < n; i++)
	{
		int p, w;
		cin >> p >> w;
#ifdef DBG
		cout << "= Phase #" << (i + 1) << " price=" << p << ", weight=" << w << endl;
#endif
		if (dp[w] == 0 || dp[w] > p)
			dp[w] = p;
		for (int j = w; j <= f; j++)
		{
			if (dp[j - w] == 0) continue;
			int calc = dp[j - w] + p;
			bool overwrite = dp[j] == 0 || dp[j] > calc;
			dp[j] = overwrite ? calc : dp[j];
#ifdef DBG
			cout << "dp[" << j << "] " << (overwrite ? "->" : "==") << ' ' << dp[j] << " (calc=dp[j-w]+p=dp[" << j-w << "]+" << p <<"]=" << dp[j - w] << '+' << p << ')' << endl;
#endif
		}
	}

#ifdef DBG
	for (int i = 0; i <= f; i++)
		cout << "dp[" << i << "] " << (i == f ? "->" : "-=") << ' ' << dp[i] << endl;
#endif

	int l = dp[max(f, 0)];
	cout << (l == 0 ? -1 : l) << endl;
	return 0;
}