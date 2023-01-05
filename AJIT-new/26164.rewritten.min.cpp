/*
돼지 저금통
https://43.200.211.173/contest/17/problem/26164
C-Minifier-friendly version
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int e, f, n; cin >> e >> f >> n; f -= e;
	int s = max(2, f + 1);
	int* d = new int[s];
	fill(d, d + s, 0);
	for (int i = 0; i < n; i++)
	{
		int p, w; cin >> p >> w;
		if (d[w] == 0 || d[w] > p)
			d[w] = p;
		for (int j = w; j <= f; j++)
		{
			if (d[j - w] != 0)
			{
				int c = d[j - w] + p;
				if (d[j] == 0 || d[j] > c)
					d[j] = c;
			}
		}
	}
	int l = d[max(f, 0)];
	cout << (l == 0 ? -1 : l) << endl;
	return 0;
}