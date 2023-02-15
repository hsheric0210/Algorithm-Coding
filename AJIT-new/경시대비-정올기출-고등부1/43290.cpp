/*
관중석
https://43.200.211.173/contest/17/problem/43290
소요시간: 2시간 남짓
*/
#include<iostream>
using namespace std;
int i, j, k, l, d1, d2, p, q, r;
unsigned long long t;
int cache[2000][2000];
int gcd(int a, int b)
{
	if (cache[a][b] == 0)
	{
		p = a, q = b;
		while (1)
		{
			r = p % q;
			if (r == 0)
			{
				cache[a][b] = q;
				break;
			}
			p = q;
			q = r;
		}
	}
	return cache[a][b];
}
int main()
{
	cin >> d1 >> d2;
	for (i = d1; i <= d2; i++) t += i;
	t -= d2 - d1; // 같은 시초선 위에 있는 n개의 좌석들 중, 맨 앞에 있는 것을 제외한 n-1개 제외
	for (i = d1; i < d2; i++)
	{
		for (k = i + 1; k < d2; k++)
		{
			l = gcd(i, k);
			t -= l - 1;
		}
	}
	cout << t << endl;
}