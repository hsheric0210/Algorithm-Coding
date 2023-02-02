/*
LIS 길이 구하기 - O(n^2) 알고리즘
https://www.acmicpc.net/problem/9252
입력: 수열 길이 N, 수열 S (N <= 1000)
출력: LIS의 길이
*/
#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, n, *arr, *dp;
int main()
{
	cin >> n;
	arr = new int[n], dp = new int[n]{0};
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp[j] > k) // 구현 실수 I: 'arr[j] < arr[i]'를 'arr[i] < arr[j]'로 바꾸어 썼다
				k = dp[j];
		dp[i] = k + 1;
	}
	cout << *max_element(dp, dp + n) << endl;
}