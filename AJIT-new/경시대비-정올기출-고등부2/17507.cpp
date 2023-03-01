/*
점프(정올2019)
https://43.200.211.173/contest/17/problem/17507
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
int a[32], b[32], c[32];
void build()
{
	b[1] = 1;
	for (i = 1; i < 31; i++)
	{
		a[i] = (int)pow(2, i) - 1;
		if (i > 1)
			b[i] = b[i - 1] + (i - 1);
		cout << "a[" << i << "]=" << a[i] << ", b[" << i << "]=" << b[i] << endl;
	}
}
int brute_force(int n, int depth) // we can try brute-forcing when range is enoughly small
{
	if (n == 0) return depth;
	auto lb = lower_bound(a, a + 31, n);
	if (*lb != n)
		lb--;
	return brute_force(n - (*lb), depth + (lb - a));
}
int div_and_conq(int start, int depth)
{
	c[0] = -1;
	for (j = 1; j < 31; j++) // init table
	{
		c[j] = start + a[j];
		//cout << start << " + " << "(a[" << j << "]=" << a[j] << ") = " << c[j] << endl;
	}
	auto lb = lower_bound(c, c + 31, y);
	if (*lb == y)
	{
		//cout << "found exact on i=" << lb - c << ", val=" << *lb << endl;
		return depth + (lb - c); // found exact
	}
	lb--;
	//cout << "found on i=" << lb - c << ", val=" << *lb << ", original_depth=" << depth << ", depth_addition=" << lb - c << endl;
	return div_and_conq(*lb, depth + (lb - c)); // found green
}
vector<int>deltas;
int main()
{
	build();
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> x >> y;
		if (x == y)
		{
			cout << brute_force(y, 0) << endl;
		}
		else
		{
			auto lb = lower_bound(a, a + 31, y);
			m = max(x - 1, a[lb - a - 1]);
			l = div_and_conq(m, lb - a - 1);
			s = *max_element(b, b + (lb - a));
			cout << "divcnq=" << l << ", b[i-1]=" << s << endl;
			int sol1 = max(s, l);
			cout << sol1 << endl; // b(i-1) 이전의 수들은 어차피 싹다 b(i-1)보다 작을 것이므로 볼 필요 없다.
			q = 0;
			for (p = x; p <= y; p++)
			{
				r = brute_force(p, 0);
				//cout << "j(" << p << ")=" << r << endl;
				if (r > q)
					q = r;
			}
			w = 0;
			for (u = a[lb - a - 1]+1; u <= y; u++)
			{
				v = brute_force(p, 0);
				cout << "#2 j(" << u << ")=" << v << endl;
				if (v > w)
					w = v;
			}
			if (sol1 != q)
			{
				cout << "[!] max value mismatched on: range=" << x << ".." << y << " -> thought_solution=" << sol1 << ", brute_forced=" << q << ", delta=" << sol1 - q << endl;
				//deltas.push_back(sol1 - q);
			}
			if (l != w)
			{
				cout << "[!] div_n_cnq mismatched on: range=" << m+1 << ".." << y << " -> dnq=" << l << ", brute_forced=" << w << ", delta=" << l - w << endl;
				deltas.push_back(l-w);
			}
		}
	}
	for (auto a = deltas.begin(); a != deltas.end(); a++)
		cout << "Delta=" << *a << endl;
}