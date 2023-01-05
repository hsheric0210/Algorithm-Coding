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
	for (int i = 0; i < n; i++) // i: 0 until n
	{
		int v = a[i];
		int M = 0;
		for (int j = 0; j < i; j++) // j: 0 until i - d[0..(i-1)]까지의 원소들을 순회하며, a[i] 앞에 붙을 수 있는 원소 a[j]들 중 d[j] 값이 가장 큰 것을 찾는다 - Heap으로 최적화 가능하다
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