/*
소들의 시위 (***)
https://43.200.211.173/contest/17/problem/80022
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, j;
int main()
{
	cin >> n;
	int* arr = new int[n + 1]{ 0 };
	int* sum = new int[n + 1]{ 0 };
	int* groups = new int[n + 1]{ 0 };
	sum[0] = 0;
	groups[0] = 1;
	for (i = 1; i <= n; i++)
		cin >> arr[i];

	for (i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (sum[i] - sum[j] >= 0)
			{
				groups[i] += groups[j];
			}
		}
	}
	cout << *max_element(groups + 1, groups + n + 1) << endl;
}
