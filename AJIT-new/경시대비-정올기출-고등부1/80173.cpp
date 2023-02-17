/*
고집수
https://43.200.211.173/contest/17/problem/80173
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, p1, p2;
vector<int>v;
int decAndMul(int n)
{
	m = o = 1;
	for (k = 0, l = log10(n); k <= l; k++)
	{
		o *= n / m % 10; // decompose와 multiplication을 동시에!
		m *= 10;
	}
	return o;
}
int main()
{
	cin >> p1 >> p2 >> n;
	for (i = p1; i <= p2; i++)
	{
		p = i;
		for (j = 1; j <= n; j++)
		{
			p = decAndMul(p);
			if (p > 0 && p < 10 && j < n)
				goto fail;
		}
		if (p > 0 && p < 10)//한자리 자연수
			v.push_back(i);
	fail:
		;
	}
	cout << v.size() << endl;
	for (auto a = v.begin(); a != v.end(); a++)
		cout << *a << endl;
}