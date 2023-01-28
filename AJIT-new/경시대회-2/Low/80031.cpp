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
	arr = new int[k] {0};
	for (i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr, arr + k, greater<int>());

	if (k >= n)
	{
		cout << *min_element(arr, arr + n) << endl;
		return 0;
	}

	int pivot = 1;
	for (i = 0; i < k; i++)
		pivot += arr[i] / (n / k);
	pivot /= k;
	int actual = -1;
	int prev = -1;
	int prev_sign = 0;
	while (1)
	{
		// TODO: binary search
		actual = 0;
		for (i = 0; i < k; i++)
		{
			actual += arr[i] / max(pivot, 1);
		}

		if (actual == n)
		{
			//cout << prev_sign << " " << pivot << " (a=" << actual << ')' << endl;
			pivot += prev_sign;
		}
		else if (prev == n && actual < n) // to output maximum possible pivot
		{
			cout << pivot - prev_sign << endl;
			return 0;
		}
		if (actual < n)
		{
			pivot--;
			//cout << "-- " << pivot << " (a=" << actual << ')' << endl;
			prev_sign = -1;
		}
		else if (actual > n)
		{
			pivot++;
			//cout << "++ " << pivot << " (a=" << actual << ')' << endl;
			prev_sign = 1;
		}
		prev = actual;
	}
}