/*
앉을 수 있는 자리
https://43.200.211.173/contest/19/problem/3500
*/
#include<iostream>
using namespace std;
int n, i, * arr, c;
int main()
{
	cin >> n;
	arr = new int[n];
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++)
	{
		if ((i == 0 || !arr[i - 1]) // 왼쪽 자리 비어있음
			&& !arr[i] // 지금 이 자리 비어있음
			&& (i == n - 1 || !arr[i + 1])) // 오른쪽 자리 비어있음
			c++;
	}
	cout << c;

}