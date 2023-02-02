/*
LIS 길이 구하기 - O(n^2) 알고리즘
https://www.acmicpc.net/problem/9252
입력: 수열 길이 N, 수열 S (N <= 1000)
출력: LIS의 길이
*/
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int i, j, n, * arr;
pair<int, int>* dp;
int main()
{
	cin >> n;
	arr = new int[n];
	dp = new pair<int, int>[n];
	fill(dp, dp + n, make_pair(0, -1));
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++)
	{
		pair<int, int> k = { 0,0 };
		for (j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp[j].first > k.first)
				k = { dp[j].first, j };
		dp[i] = { k.first + 1, k.second };
	}
	//backtrack
	deque<pair<int, int>>q;
	deque<int>lis;
	auto mx = *max_element(dp, dp + n, [](auto a, auto b) {return a.first < b.first; });
	cout << mx.first << endl;
	q.push_back(mx);
	while (!q.empty())
	{
		auto top = q.back();
		q.pop_back();
		if (top.second <= 0)
			break;
		lis.push_front(arr[top.second]);
		q.push_back(dp[top.second]);
	}
	for (auto a = lis.begin(); a != lis.end(); a++)
		cout << *a << ' ';
	cout << endl;
}