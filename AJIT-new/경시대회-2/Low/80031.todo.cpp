/*
케이블 자르기
https://43.200.211.173/contest/18/problem/80031
*/
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, * arr;
int main()
{
	cin >> k >> n;
	arr = new int[k];
	for (i = 0; i < k; i++) cin >> arr[i];
	int lb = 1, ub = *max_element(arr, arr + k);
	if (k >= n)
	{
		// we don't need to calculate!
		cout << ub << endl;
		return 0;
	}
	while (1)
	{
		
	}
}