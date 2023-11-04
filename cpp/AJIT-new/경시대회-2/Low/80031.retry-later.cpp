/*
케이블 자르기
https://43.200.211.173/contest/18/problem/80031
*/
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, * arr;
int main()
{
	cin >> k >> n;
	arr = new int[k];
	for (i = 0; i < k; i++) cin >> arr[i];
	if (k >= n)
	{
		// we don't need to calculate!
		cout << *max_element(arr, arr + k) << endl;
		return 0;
	}
	// use upper_bound
	vector<pair<int, int>>dp;
	for (i = 1; i <= 10000; i++)
	{
		l = 0;
		for (j = 0; j < k; j++)
			l += arr[j] / i;
		dp.push_back({ i, l });
		if (l < n)
			break;
	}
	// before binary search, we need to sort
	reverse(dp.begin(), dp.end());
	for (auto a = dp.begin(); a != dp.end(); a++)
		cout << "dp[" << distance(dp.begin(), a) << "]={" << a->first << "," << a->second << "}" << endl;
	pair<int, int> vc = { 0,n };
	cout << lower_bound(dp.begin(), dp.end(), vc, [](auto a, auto b) {return a.second < b.second; })->first << endl;
}