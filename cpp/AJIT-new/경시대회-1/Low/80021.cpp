/*
A Game
https://43.200.211.173/contest/17/problem/80021
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, c, a = 0, b = 0, c, i;
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> c;
		if (i % 2 == 0)
			a += c;
		else
			b += c;
	}
	cout << max(a, b) << ' ' << min(a, b) << endl;
}