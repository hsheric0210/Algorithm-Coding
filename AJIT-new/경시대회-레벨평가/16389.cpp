/*
완전 제곱수
https://43.200.211.173/contest/19/problem/16389
*/
#include<iostream>
using namespace std;
int n, i, j, *arr, cnt = 0;
int main()
{
	cin >> n;
	arr = new int[501];
	for (i = 1; i <= 500; i++)
		arr[i] = i * i;
	for (i = 500; i > 0; i--)
		for (j = i - 1; j > 0; j--)
			if (arr[i] - arr[j] == n)
				cnt++;
			else if (arr[i] - arr[j] > n)
				break;
	cout << cnt << endl;
}