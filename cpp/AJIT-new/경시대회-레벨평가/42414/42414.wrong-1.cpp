/*
돼지 저금통
https://43.200.211.173/contest/19/problem/42414
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct _A { int p, w; } A;
int n, m, i, j, k, l, * dp;
A* arr;
bool acmp(A a, A b) { return a.w > b.w || a.p > b.p; }
int main()
{
	cin >> i >> j >> n;
	m = j - i;
	arr = new A[n];
	dp = new int[m + 1]{0};
	for (i = 0; i < n; i++)
	{
		cin >> j >> k;
		arr[i] = { j, k };
	}
	sort(arr, arr + n, acmp);
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (j % arr[i].w == 0)
			{
				// 구현 실수 I: 이 부분에서 
				if (dp[j] > 0)
					dp[j] = min(dp[j], dp[j-arr[i].w] + arr[i].p);
				else
					dp[j] = dp[j - arr[i].w] + arr[i].p;
			}
		}
	}

	//for (i = 0; i <= m; i++)
	//{
	//	cout << "dp[" << i << "]=" << dp[i] << endl;
	//}

	if (dp[n] > 0)
		cout << dp[m] << endl;
	else
		cout << -1 << endl;
}