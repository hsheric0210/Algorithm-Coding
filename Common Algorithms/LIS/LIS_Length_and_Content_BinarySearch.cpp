/*
LIS 길이 구하기 - O(nLog(n)) 알고리즘 - Lower bound 이진 탐색 사용
https://www.acmicpc.net/problem/9252
입력: 수열 길이 N, 수열 S
출력: LIS의 길이와 LIS 문자열
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
int i, j, k;
int main()
{
	cin >> k;
	vector<pair<int, int>>arr(k, { -1, -1 });
	vector<pair<int, int>>v(1, { -1,-1 }); // FIRST: evaluation entry, SECOND: backtrack index
	vector<int>bt(k + 1, -1);
	for (i = 0; i < k; i++)
	{
		cin >> j;
		arr[i] = { j, i };

		if (v.back().first < arr[i].first)
		{
			bt[arr[i].second] = v.back().second;
			v.push_back(arr[i]);
		}
		else
		{
			auto a = lower_bound(v.begin(), v.end(), arr[i], [](auto a, auto b) {return a.first < b.first; });
			bt[arr[i].second] = (a - 1)->second;
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