/*
개미의기나긴모험
https://43.200.211.173/contest/17/problem/80002
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, d = 0, cx = 0, cy = 0; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		d += abs(x - cx) + abs(y - cy);
		cx = x; cy = y;
	}
	cout << d << endl;
}