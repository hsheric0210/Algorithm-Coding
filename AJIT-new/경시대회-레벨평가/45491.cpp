/*
나무 자르기
https://43.200.211.173/contest/19/problem/45491
*/
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, * arr, ** dp;
vector<int> tmp;
int main()
{
	// init
	cin >> l >> n;
	n += 2;
	arr = new int[n] { 0 };
	arr[n - 1] = l;
	dp = new int* [n];
	for (i = 0; i <= n; i++)
		dp[i] = new int[n] { 0 };

	//input
	for (i = 1; i < n - 1; i++)
		cin >> arr[i];

	//dp
	for (k = 2; k <= n; k++) // gap
		for (i = 0; i < n; i++) // vert
			for (j = k; j < n; j++) // hori
				if (j - i == k) // only fill specified gaps
				{
					int m = 999;
					tmp.clear();
					for (l = 1; l < k; l++)
						tmp.push_back(dp[0][l] + dp[l][k]);
					m = *min_element(tmp.begin(), tmp.end());
					dp[i][j] = (arr[j] - arr[j - k]) + m;
				}

	//debug build dp-t
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	//debug

	cout << dp[0][n - 1] << endl;
}
