/*
최장 증가 부분수열(Longest Increasing subsequence)
https://43.200.211.173/contest/18/problem/80032

nlog(n) LIS 구현 + 백트래킹을 이용한 LIS 문자열 출력
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include<deque>
using namespace std;
int i, j, k;
vector<pair<int, int>>v(1, { -1,-1 });
int main()
{
	cin >> k;
	vector<pair<int, int>>arr(k);
	vector<int>bt(k + 1, -1);
	for (i = 0; i < k; i++)
	{
		cin >> j;
		arr[i] = { j,i };
		if (v.back().first < j)
		{
			bt[i] = v.back().second;
			v.push_back(arr[i]);
		}
		else
		{
			auto a = lower_bound(v.begin(), v.end(), arr[i], [](auto alpha, auto beta) { return alpha.first < beta.first; }); // 구현 실수 I: comparator 구현 빼먹음
			bt[i] = (a - 1)->second;
			*a = arr[i];
		}
	}
	deque<int>dmp;
	for (i = v.back().second; i >= 0; i = bt[i])
		dmp.push_front(arr[i].first);
	cout << dmp.size() << endl;
	for (auto a = dmp.begin(); a != dmp.end(); a++)
		cout << *a << ' ';
	cout << endl;
}