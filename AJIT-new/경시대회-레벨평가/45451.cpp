/*
A Game
https://43.200.211.173/contest/19/problem/45451
����: ����� �ùķ��̼� ������ ���� ��������, �ǻ��� �� � �������ٵ� �ع��� ������ ����
*/
#include<iostream>
using namespace std;
int n, * arr, i, a, b;
int main()
{
	cin >> n;
	arr = new int[n];
	for (i = 0; i < n; i++)
		cin >> arr[i];

	for (i = 0; i < n; i += 2)
		a += arr[i];
	for (i = 1; i < n; i += 2)
		b += arr[i];

	cout << max(a, b) << ' ' << min(a, b) << endl;
}