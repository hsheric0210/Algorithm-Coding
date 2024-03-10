/*
관중석
https://43.200.211.173/contest/17/problem/43290
소요시간: 2시간 남짓
*/
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cmath>
#include<set>
using namespace std;
int i, j, k, l, n, p, q, r, d1, d2;
int cnts[2005];
set<int> gcds;
int gcd(int a, int b) // 유클리드 호제법
{
	p = a, q = b;
	while (1)
	{
		r = p % q;
		if (r == 0)
			return q;
		p = q;
		q = r;
	}
}
void testwriter(int a, int b)
{
	set<int>dup;
	for (i = a; i <= b; i++)
	{
		for (j = 0; j < 360; j += 360 / i)
		{
			if (dup.find(j) != dup.end())
				continue;
			cout << j << " ";
			k++;
			dup.insert(j);
		}
		cout << endl;
	}
	cout << "expected answer=" << k << endl;
}
int main()
{
	cin >> d1 >> d2;
	//testwriter(d1, d2);
	if (d1 == d2)
	{
		cout << d2 << endl;
		return 0;
	}

	for (i = d1; i < d2; i++)
	{
		for (j = i + 1; j <= d2; j++)
		{
			k = gcd(i, j); // use set to deduplicate, to prevent excess prime factorization
			cnts[k] = k;
		}
	}
	for (i = d1; i <= d2; i++) // real rings
	{
		cnts[i] = i;
	}
	for (i = 1; i < d2; i++)
	{
		if (cnts[i] == 0) // skip redundant loop
			continue;
		//cout << "-" << cnts[i] << " from " << i + i << " to " << d2 << endl;
		for (j = i + i; j <= d2; j += i)
		{
			cnts[j] -= cnts[i];
		}
	}
	cout << accumulate(cnts, cnts + d2 + 1, 0) << endl;
}