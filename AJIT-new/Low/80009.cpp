/*
���������� ���ڸ� �����
https://43.200.211.173/contest/17/problem/80009
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, a, b, M;
int lis(int l, int* a)
{
	int* lis = new int[l + 1]{ 0 };
	for (i = 0; i < l; i++) // '0 until arrlen' ('1 until arrlen' �ϸ� Ʋ����! 23-01-05�� �̰Ͷ����� 5�� �������� Ʋ�ȴ�!)
	{
		// LIS //
		M = 0;
		for (int j = 0; j < i; j++) // '0 until i' -> j�� ������ ���ؼ�:
			if (a[j] < a[i] && lis[j] > M) // 'a[j] < a[i] �� �����ϴ� j�� ���� dp[j] �� �ִ��� ���Ѵ� (Heap ��밡��)
				M = lis[j];
		lis[i] = M + 1;
	}
	return *max_element(lis, lis + l);
}
int main()
{
	cin >> n;
	int* arr = new int [n] {0};
	for (i = 0; i < n; i++) cin >> arr[i];

	a = lis(n, arr);
	reverse(arr, arr + n);
	b = lis(n, arr);
	if (a > b) cout << "LEFT" << endl;
	else if (a < b) cout << "RIGHT" << endl;
	else cout << "IDGARA" << endl;
}