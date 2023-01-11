/*
사탕 담아주기
https://43.200.211.173/contest/17/problem/80016
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
typedef struct _candy
{
	int a; int b; int maxcnt;
} candy;
bool cm(candy a, candy b) { return a.a * ((double)m / a.b) < b.a * ((double)m / b.b); }
int main()
{
	cin >> n >> m;
	candy* cs = new candy[n];
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cs[i] = { a,b,c };
	}
	sort(cs, cs + n, cm);
	int cap = m, i = 0, cnt = 0;
	double cost = 0.0;
	while (cap > 0)
	{
		if (cnt >= cs[i].maxcnt)
		{
			cnt = 0; i++;
		}
		if (cap >= cs[i].b)
		{
			cost += cs[i].a;
			cap -= cs[i].b;
		}
		else if (cap > 0)
		{
			cost += cs[i].a * ((double)cap / cs[i].b);
			cap -= cap;
		}
		cnt++;
	}
	cout << (int)ceil(cost) << endl;
}