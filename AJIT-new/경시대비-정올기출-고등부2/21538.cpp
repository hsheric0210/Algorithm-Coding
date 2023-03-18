/*
초직사각형 - 정올2021
https://43.200.211.173/contest/17/problem/21538
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define LL unsigned long long
vector<int>v[4];
int i, j, k, l, m, n, o, p, q;
LL a[4], s, t;
int cmp(int x, int y)
{
	// prevent int overflow
	s = ((LL)a[x] + v[x].back()) * a[y];
	t = (LL)a[x] * (a[y] + v[y].back());
	return s > t ? x : y;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (i = 0; i < 4; i++)
	{
		cin >> a[i];
		v[i].push_back(-1); // to pop '-1' when all card is used
	}
	for (i = 0; i < n; i++)
	{
		char c;
		cin >> c >> o;
		v[c-'A'].push_back(o);
	}
	for (i = 0; i < 4; i++)
		sort(v[i].begin(), v[i].end());
	for (i = 0; i < k; i++)
	{
		o = cmp(0, 1);
		p = cmp(2, 3);
		q = cmp(o, p);
		cout << (char)(q+'A') << ' ' << v[q].back() << '\n';
		a[q] += v[q].back();
		v[q].pop_back();
	}
}
