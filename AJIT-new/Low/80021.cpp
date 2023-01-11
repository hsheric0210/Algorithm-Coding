/*
A Game
https://43.200.211.173/contest/17/problem/80021
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, c, a = 0, b = 0; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c; cin >> c;
		if (i % 2 == 0)
			a += c;
		else
			b += c;
	}
	cout << max(a, b) << ' ' << min(a, b) << endl;
}