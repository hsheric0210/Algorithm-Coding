/*
박테리아 번식
https://43.200.211.173/contest/17/problem/80010
*/
#include <iostream>
using namespace std;
int n, i, d, c = 1;
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> d;
		if (d == 0)
		{
			if (c % 2 != 0) c--;
			c /= 2;
		}
		else if (d == 1)
		{
			c *= 3;
		}
	}
	cout << c << endl;
}