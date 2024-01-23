/*
셀로판지
https://43.200.211.173/contest/18/problem/80047
*/
#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, p, q;
int arr[60005];
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> p >> q;
		for (j = p; j < q; j++)
			arr[j + 30000]++;
	}
	cout << *max_element(arr, arr + 60000) << endl;
}