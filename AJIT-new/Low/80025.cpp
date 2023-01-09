/*
회의실 배정(room)
https://43.200.211.173/contest/17/problem/80025
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _mt
{
	int bgn; int end;
} mt;
bool mc(mt a, mt b) { return a.bgn == a.end ? (a.end - a.bgn) > (a.end - a.bgn) : a.bgn > a.end; }
int main()
{
	int n; cin >> n;
	mt* ma = new mt[n];
	int* cs = new int[n] {0};
	for (int i = 0; i < n; i++)
	{
		int b, e; cin >> b >> e;
		ma[i] = { b, e };
	}
	sort(ma, ma + n, mc);
	for (int k = 0; k < n; k++)
	{
		int pE = ma[k].end, pI = k, c = 1;
		while (true)
		{
			int m = 999999;
			int mi = -1;
			for (int i = 0; i < n; i++)
			{
				if (ma[i].bgn >= pE && ma[i].end < m)
				{
					m = ma[i].end;
					mi = i;
				}
			}
			if (mi < 0) break;
			pE = ma[mi].end;
			pI = mi;
			c++;
		}
		cs[k] = c;
	}
	cout << *max_element(cs, cs + n) << endl;
}