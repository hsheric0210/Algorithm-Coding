/*
빠진 카드
https://43.200.211.173/contest/19/problem/3238
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, i, j, * arr;
int main()
{
	cin >> n;
	arr = new int[n + 2]{ 0 }; // SKILL: arr[0], arr[n+1]을 패딩값으로 사용
	arr[n + 1] = n + 1;
	for (i = 1; i < n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n);
	for (i = 1; i <= n + 1; i++)
		if (arr[i] - arr[i - 1] > 1)
		{
			cout << min(max(arr[i] - 1, 1), n) << endl;
			return 0;
		}
}