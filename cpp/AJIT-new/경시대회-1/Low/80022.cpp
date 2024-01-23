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
	long long* groups = new long long[n + 1]{ 0 };
	groups[0] = 1;
	for (i = 1; i <= n; i++)
		cin >> arr[i];

	for (i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i];

	for (i = 1; i <= n; i++)
		for (j = 0; j < i; j++)
			if (sum[i] - sum[j] >= 0)
				groups[i] += groups[j] % 1000000009;
	cout << groups[n] % 1000000009 << endl;
	// '% 1000000009'를 한 값을 groups[i]에 더하는 것이기에
	// max_element를 쓰면 안 된다. (내 4시간...)
	//cout << *max_element(groups + 1, groups + n + 1) << endl;
}
