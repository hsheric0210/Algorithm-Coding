/*
숫자 사슬
https://43.200.211.173/contest/17/problem/80012
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int* decompose(int n, int l)
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
int recompose(int* de, int l)
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
	int np = -1;
	vector<int> c;
	c.push_back(n);
	while (true)
	{
		int* asc = decompose(n, l);
		int* desc = new int[l] {0};
		copy(asc, asc + l, desc);
		sort(asc, asc + l, greater<int>());
		sort(desc, desc + l, less<int>());
		int g = recompose(asc, l) - recompose(desc, l);
		n = g;
		if (np == g)
			break;
		c.push_back(g);
		np = g;
	}
	cout << c.size() << endl;
	for (auto i = c.begin(); i != c.end(); i++)
		cout << *i << endl;
}