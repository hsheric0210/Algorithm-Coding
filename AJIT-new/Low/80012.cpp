/*
숫자 사슬
https://43.200.211.173/contest/17/problem/80012
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int* de(int n, int l)
{
	int* arr = new int[l] {0};
	int mul = 1;
	for (int i = 0; i < l; i++)
	{
		arr[l - i - 1] = n / mul % 10;
		mul *= 10;
	}
	return arr;
}
int re(int* de, int l)
{
	int ans = 0, mul = 1;
	for (int i = 0; i < l; i++)
	{
		ans += de[l - i - 1] * mul;
		mul *= 10;
	}
	return ans;
}
int main()
{
	int n; cin >> n;
	int l = (int)ceil(log10(n));
	vector<int> c;
	c.push_back(n);
	while (true)
	{
		int* as = de(n, l);
		int* ds = new int[l] {0};
		copy(as, as + l, ds);
		sort(as, as + l, greater<int>());
		sort(ds, ds + l, less<int>());
		int g = re(as, l) - re(ds, l);
		n = g;
		if (find(c.begin(), c.end(), n) != c.end())
			break;
		c.push_back(g);
	}
	cout << c.size() << endl;
	for (auto i = c.begin(); i != c.end(); i++)
		cout << *i << endl;
}