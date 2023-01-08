/*
박테리아 번식
https://43.200.211.173/contest/17/problem/80010
*/
#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int c = 1;
	for (int i = 0; i < n; i++)
	{
		int d; cin >> d;
		switch (d)
		{
		case 0:
			if (c % 2 != 0)
				c--;
			c /= 2;
			break;
		case 1:
			c *= 3;
			break;
		}
	}
	cout << c << endl;
}