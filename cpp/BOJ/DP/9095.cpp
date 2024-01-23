/*
1, 2, 3 더하기
https://www.acmicpc.net/problem/9095
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int f(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;

	return f(n - 1) + f(n - 2) + f(n - 3);
}

int main(void)
{
	int n;
	cin >> n;

	int* arr = new int[n]();

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr[i] = f(x);
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	delete[] arr;
}