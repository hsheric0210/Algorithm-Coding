/*
이번 주 로또
https://43.200.211.173/contest/19/problem/3156
*/
#include<iostream>
#include<algorithm>
using namespace std;
int* a, * b, bn, i, j, p = 0, q = 0;
int main()
{
	a = new int[6], b = new int[6];
	for (i = 0; i < 6; i++)
		cin >> a[i];
	cin >> bn;
	for (i = 0; i < 6; i++)
		cin >> b[i];

	sort(a, a + 6);
	sort(b, b + 6);
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			if (a[i] == b[j])
				q++;

	// 1등
	if (q == 6)
		p = 1;

	// 2등
	if (p <= 0 && q == 5 && find(b, b + 6, bn) != b + 6)
		p = 2;

	// 3등-5등
	if (p <= 0 && q > 2)
		p = 6 - (q - 2);

	cout << p << endl;
}