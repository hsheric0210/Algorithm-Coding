/*
개미의기나긴모험
https://43.200.211.173/contest/17/problem/80002
Manhattan distance
*/
#include <iostream>
#include <math.h>
using namespace std;
int n, i, lx, ly, d = 0, gx = 0, gy = 0;
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> lx >> ly;
		d += abs(lx - gx) + abs(ly - gy);
		gx = lx; gy = ly;
	}
	cout << d << endl;
}