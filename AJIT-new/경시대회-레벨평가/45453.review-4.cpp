/*
소들의 시위
https://43.200.211.173/contest/19/problem/45453
*/
#include<iostream>
using namespace std;
int i, j, n, * a, * b;
int main()
{
	cin >> n;
	a = new int[n + 1]{ 0 };
	b = new int[n + 1]{ 1 };
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (i = 1; i <= n; i++)
		for (j = 0; j < i; j++)
			if (a[i] >= a[j])
				b[i] = (b[i] % 1000000009 + b[j] % 1000000009) % 1000000009;
	cout << b[n] % 1000000009 << endl;
}