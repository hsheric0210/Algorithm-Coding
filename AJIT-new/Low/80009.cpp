/*
나폴레옹의 모자른 군사들
https://43.200.211.173/contest/17/problem/80009
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, a, b, M;
int lis(int l, int* a)
{
	int* lis = new int[l + 1]{ 0 };
	for (i = 0; i < l; i++) // '0 until arrlen' ('1 until arrlen' 하면 틀린다! 23-01-05에 이것때문에 5번 연속으로 틀렸다!)
	{
		// LIS //
		M = 0;
		for (int j = 0; j < i; j++) // '0 until i' -> j의 범위에 대해서:
			if (a[j] < a[i] && lis[j] > M) // 'a[j] < a[i] 를 만족하는 j에 대한 dp[j] 중 최댓값을 구한다 (Heap 사용가능)
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