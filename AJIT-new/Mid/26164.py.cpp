/*
돼지 저금통
https://43.200.211.173/contest/17/problem/26164
26164.py로부터 포팅됨
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define DBG
int main()
{
	int x, y; cin >> x >> y; y -= x;
	int s = max(2, y + 1);
	int* pig = new int[s];
	fill(pig, pig + s, 0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, w;
		cin >> p >> w;
		if (pig[w] == 0 || p < pig[w])
			pig[w] = p;
		for (int j = w; j <= y; j++)
		{
			if (pig[j - w] == 0) continue;
			else if (pig[j - w] + p < pig[j] || pig[j] == 0)
				pig[j] = pig[j - w] + p;
		}
	}

	if (pig[y] == 0)
		cout << -1 << endl;
	else
		cout << pig[y] << endl;
	return 0;
}