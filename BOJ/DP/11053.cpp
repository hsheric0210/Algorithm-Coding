/*
가장 긴 증가하는 부분 수열
https://www.acmicpc.net/problem/11053
*/
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int lis(int n, int* a)
{
	// d[n] = 'n을 마지막 값으로 가지는 LIS 길이'
	int* d = new int[n]{ 0, };
	for (int i = 0; i < n; i++) // i: 1 until n
	{
		int v = a[i];
		int M = 0;
		for (int j = 0; j < i; j++) // j: 0 until i
			if (a[j] < v && d[j] > M)
				M = d[j];
		d[i] = M + 1;
	}

	int r = *max_element(d, d + n);
	delete[] d;
	return r;
}

int main()
{
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << lis(n, a) << endl;
}