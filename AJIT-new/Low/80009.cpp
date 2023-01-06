/*
���������� ���ڸ� �����
https://43.200.211.173/contest/17/problem/80009
*/
#include <iostream>
#include <algorithm>
using namespace std;
int lis(int arrlen, int* arr)
{
	int* dp = new int[arrlen + 1] {0};
	fill(dp, dp + arrlen + 1, 0);
	for (int i = 0; i < arrlen; i++) // '0 until arrlen' ('1 until arrlen' �ϸ� Ʋ����! 23-01-05�� �̰Ͷ����� 5�� �������� Ʋ�ȴ�!)
	{
		int v = arr[i];
		int M = 0;
		for (int j = 0; j < i; j++) // '0 until i' -> j�� ������ ���ؼ�:
			if (arr[j] < v && dp[j] > M) // 'a[j] < a[i] �� �����ϴ� j�� ���� dp[j] �� �ִ��� ���Ѵ� (Heap ��밡��)
				M = dp[j];
		dp[i] = M + 1;
	}
	return *max_element(dp, dp + arrlen);
}
int main()
{
	int n; cin >> n;
	int* arr = new int [n] {0};
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int lis_a = lis(n, arr);
	reverse(arr, arr + n);
	int lis_b = lis(n, arr);
	if (lis_a > lis_b)
		cout << "LEFT" << endl;
	else if (lis_a < lis_b)
		cout << "RIGHT" << endl;
	else
		cout << "IDGARA" << endl;
	//cout << "A=" << lis_a << ", B=" << lis_b << endl;
}