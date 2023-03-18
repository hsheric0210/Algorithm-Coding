/*
햄버거 분배
http://ajit.co.kr/contest/28/problem/25038
*/
#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, x,y;
char a[20005], b, c, d;
int main()
{
	cin >> n >> k >> a;
	for (i = 0; i < n; i++)
	{
	reloop:
		l = 1;
		b = a[i];
		if (b == 0) // if current entry is empty, skip
			continue;
		c = b == 'H' ? 'P' : 'H';
		for (j = max(i - k, 0); j <= i + k; j++)
		{
			if (j == i) continue; // skip myself
			if (a[j] != 0)
				l = 0;
			if (a[j] == c)
			{
				m++;
				a[i] = a[j] = 0;
				i = (j == i + 1) ? i + 2 : i + 1;
				goto reloop;
			}
		}
		if (l)
		{
			break;
		}
	}
	cout << m << endl;
}