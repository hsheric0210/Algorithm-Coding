/*
LIS 길이 구하기 - O(nLog(n)) 알고리즘 - Lower bound 이진 탐색 사용
https://www.acmicpc.net/problem/9252
입력: 수열 길이 N, 수열 S
출력: LIS의 길이
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int i, j, k, * arr;
vector<int>v;
int main()
{
	cin >> k;
	arr = new int[k] {0}; // 구현 실수 I: arr 배열 초기화 과정 빼먹음
	for (i = 0; i < k; i++)
	{
		cin >> arr[i];
		if (v.empty() || v.back() < arr[i])
			v.push_back(arr[i]);
		else
			*lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
	}
	cout << v.size() << endl;
}