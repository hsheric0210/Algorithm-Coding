/*
회의실 배정(room)
https://43.200.211.173/contest/17/problem/80025
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _mt
{
	int x; int y;
} mt;
bool mc(mt a, mt b) { return a.x == a.y ? (a.y - a.x) > (a.y - a.x) : a.x > a.y; }
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
		int pE = ma[k].y, pI = k, c = 1;
		while (true)
		{
			int m = 999999;
			int mi = -1;
			for (int i = 0; i < n; i++)
			{
				if (ma[i].x >= pE && ma[i].y < m)
				{
					m = ma[i].y;
					mi = i;
				}
			}
			if (mi < 0) break;
			pE = ma[mi].y;
			pI = mi;
			c++;
		}
		cs[k] = c;
	}
	cout << *max_element(cs, cs + n) << endl;
}