/*
숫자 사슬
https://43.200.211.173/contest/17/problem/80012
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int a, m, n, l, g;
int* de(int n, int l) // decompose
{
	int* na = new int[l] {0};
	m = 1;
	for (int i = 0; i < l; i++)
	{
		na[l - i - 1] = n / m % 10;
		m *= 10;
	}
	return na;
}
int re(int* na, int l) // recompose
{
	a = 0;	m = 1;
	for (int i = 0; i < l; i++)
	{
		a += na[l - i - 1] * m;
		m *= 10;
	}
	return a;
}
int main()
{
	cin >> n;
	l = (int)ceil(log10(n));
	vector<int> c;
	c.push_back(n);
	while (true)
	{
		int* as = de(n, l);
		int* ds = new int[l] {0};
		copy(as, as + l, ds);
		sort(as, as + l, greater<int>());
		sort(ds, ds + l, less<int>());
		g = re(as, l) - re(ds, l);
		n = g;
		if (find(c.begin(), c.end(), n) != c.end())
			break;
		c.push_back(g);
	}
	cout << c.size() << endl;
	for (auto i = c.begin(); i != c.end(); i++)
		cout << *i << endl;
}