/*
설탕 배달
https://www.acmicpc.net/problem/2839
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int u5 = 0, u3 = 0;

	while (n >= 3)
	{
		if (n % 5 == 0)
		{
			// use 5kg bag
			n -= 5;
			u5++;
		}
		else
		{
			// use 3kg bag
			n -= 3;
			u3++;
		}
	}

	if (n > 0)
		cout << -1 << endl;
	else
		cout << u5 + u3 << endl;
}