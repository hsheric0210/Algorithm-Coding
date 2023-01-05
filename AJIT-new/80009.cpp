/*
나폴레옹의 모자른 군사들
https://43.200.211.173/contest/17/problem/80009
*/
#include <iostream>
#include <algorithm>
using namespace std;
int lis(int arrlen, int* arr)
{
	int* dp = new int[arrlen + 1] {0};
	fill(dp, dp + arrlen + 1, 0);
	for (int i = 0; i < arrlen; i++) // '0 until arrlen' ('1 until arrlen' 하면 틀린다! 23-01-05에 이것때문에 5번 연속으로 틀렸다!)
	{
		int v = arr[i];
		int M = 0;
		for (int j = 0; j < i; j++) // '0 until i' -> j의 범위에 대해서:
			if (arr[j] < v && dp[j] > M) // 'a[j] < a[i] 를 만족하는 j에 대한 dp[j] 중 최댓값을 구한다 (Heap 사용가능)
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