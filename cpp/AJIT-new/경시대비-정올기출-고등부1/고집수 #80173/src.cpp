/*
고집수
https://43.200.211.173/contest/17/problem/80173
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, p1, p2;
vector<int>v;
int decAndMul(int n)
{
	m = o = 1;
	for (k = 0, l = (int)log10(n); k <= l; k++)
	{
		q = n / m % 10;
		if (q == 0) // 더 이상 계산할 필요 x (모든 a에 대하여, a*0=0)
			break;
		o *= q; // decompose와 multiplication을 동시에!
		m *= 10;
	}
	return o;
}
int main()
{
	cin >> p1 >> p2 >> n;
	for (i = p1; i <= p2; i++)
	{
		p = i;
		for (j = 1; j <= n; j++)
		{
			p = decAndMul(p);
			if (p < 10 && j != n) goto fail; // n번 반복하기 전에 한 자리 수가 되어버림 -> 실패
		}
		if (p < 10) // n번 반복한 후에도 한 자리 자연수가 아님
			v.push_back(i);
	fail:
		;
	}
	cout << v.size() << endl;
	for (auto a = v.begin(); a != v.end(); a++)
		cout << *a << endl;
}