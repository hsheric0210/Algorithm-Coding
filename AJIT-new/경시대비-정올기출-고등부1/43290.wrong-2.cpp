/*
관중석
https://43.200.211.173/contest/17/problem/43290
소요시간: 2시간 남짓
*/
#include<iostream>
#include<set>
using namespace std;
int i, j, k, l, d1, d2, p, q, r;
unsigned long long t;
int cache[2000][2000];
int gcd(int a, int b)
{
	p = a, q = b;
	while (1)
	{
		r = p % q;
		if (r == 0)
		{
			return q;
		}
		p = q;
		q = r;
	}
}
int main()
{
	cin >> d1 >> d2;
	for (i = d1; i <= d2; i++) t += i;
	t -= d2 - d1; // 같은 시초선 위에 있는 n개의 좌석들 중, 맨 앞에 있는 것을 제외한 n-1개 제외
	int sumofgcd = 0;
	for (i = d1; i < d2; i++)
	{
		cout << "i=" << i << " (mod=" << 360.0 / i << ")" << endl;
		for (k = i + 1; k <= d2; k++)
		{
			l = gcd(i, k);
			cout << "k=" << k << " gcd=" << l << " lcm=" << (i * k / l) << endl;
				if (l > 1)
					cout << "-" << l - 1 << " @ " << k << endl;
				t -= l - 1;
		}
	}
	cout << t << endl;
}