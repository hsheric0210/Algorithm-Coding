/*
Ç³¼±_ajit
https://43.200.211.173/contest/18/problem/80029
*/
#include<iostream>
#include<algorithm>
typedef struct A {
	int i, j;
};
int ac(A a, A b) { return a.i < b.i || (a.i == b.i && a.j < b.j); }
using namespace std;
int i, j = 0, k, l, m, n, h, * a;
int main()
{
	cin >> n >> m;
	a = new int[n + 1]{ 0 };
	A* b = new A[n + 1];
	for (i = 1; i <= n; i++)
	{
		cin >> a[i]; j += a[i];
		b[i].i = a[i]; b[i].j = i;
	}
	if (m >= j)
	{
		for (i = 1; i <= n; i++) cout << a[i] << ' ';
		cout << endl;
		return 0;
	}
	sort(b + 1, b + n + 1, ac);
	h = 0;
	for (i = 1; i <= n; i = j)
	{
		l = n - i + 1;
		j = b[i].i - h;
		k = m - j * l;
		if (k >= 0)
		{
			m = k; h = b[i].i;
		}
		else break;
		for (j = i + 1; j <= n; j++)
			if (b[i].i < b[j].i)
				break;
	}

	j = m / l;
	k = m % l;
	l = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] <= h) cout << a[i] << ' ';
		else {
			l++;
			if (l <= k) cout << (h + j + 1) << ' ';
			else cout << (h + j) << ' ';
		}
	}
	cout << endl;
}