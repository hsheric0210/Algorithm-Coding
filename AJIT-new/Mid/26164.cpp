/*
돼지 저금통
https://43.200.211.173/contest/17/problem/26164
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef struct _testcase
{
	int p;
	int w;
} testcase;
//#define DBG
int main()
{
	// tw(=f-e) : 총 동전의 무게
	int e, f, n; cin >> e >> f >> n; int tw = f - e;

	testcase* tc = new testcase[n];
	for (int i = 0; i < n; i++)
	{
		// parse test cases
		int p, w;
		cin >> p >> w;
		tc[i] = { p, w };
	}
	int dpsz = max(2, tw + 1);
	int* dp = new int[dpsz];
	fill(dp, dp + dpsz, 0);
	if (tw > 0)
	{
		for (int ti = 0; ti < n; ti++)
		{
			testcase t = tc[ti];
			for (int di = 1; di <= tw; di++)
			{
				if (di % t.w == 0)
				{
					int calc = dp[di - t.w] + t.p;
					bool overwrite = dp[di] == 0 || dp[di] > calc;
					dp[di] = overwrite ? calc : dp[di];
#ifdef DBG
					cout << "> dp[" << j << "]" << (overwrite ? 'w' : ' ') << "= " << dp[j] << endl;
#endif
				}
			}
		}
#ifdef DBG
		for (int i = 0; i <= tw; i++)
		{
			cout << "< dp[" << i << "] = " << dp[i] << endl;
		}
#endif
	}
	int l = dp[max(0, tw)];
	cout << (l == 0 ? -1 : dp[max(tw, 0)]) << endl;
	//delete[] dp;
	return 0;
}