/*
월급받는 권종구
https://43.200.211.173/contest/19/problem/45567
*/
#include<iostream>
using namespace std;
int n, i, j, * arr, c;
int main()
{
	cin >> n;
	arr = new int[n];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			arr[c++] = j;
			if (c == n)
				goto brk; // SKILL: goto문을 통한 다중 루프문 탈출
		}
	brk:
	cout << arr[n - 1] << endl;
}
