/*
���� �� �����ϴ� �κ� ����
https://www.acmicpc.net/problem/11053
*/
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int lis(int n, int* a)
{
	// d[n] = 'n�� ������ ������ ������ LIS ����'
	int* d = new int[n]{ 0, };
	for (int i = 0; i < n; i++) // i: 0 until n
	{
		int v = a[i];
		int M = 0;
		for (int j = 0; j < i; j++) // j: 0 until i - d[0..(i-1)]������ ���ҵ��� ��ȸ�ϸ�, a[i] �տ� ���� �� �ִ� ���� a[j]�� �� d[j] ���� ���� ū ���� ã�´� - Heap���� ����ȭ �����ϴ�
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