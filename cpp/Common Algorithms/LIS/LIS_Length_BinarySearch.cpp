/*
LIS 길이 구하기 - O(nLog(n)) 알고리즘 - Lower bound 이진 탐색 사용
https://www.acmicpc.net/problem/9252
입력: 수열 길이 N, 수열 S
출력: LIS의 길이
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, n, * arr;
vector<int>lb;
int main()
{
	cin >> n;
	arr = new int[n];
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (lb.empty() || lb.back() < arr[i])
			lb.push_back(arr[i]);
		else
			*lower_bound(lb.begin(), lb.end(), arr[i]) = arr[i];
	}
	cout << lb.size() << endl;
}