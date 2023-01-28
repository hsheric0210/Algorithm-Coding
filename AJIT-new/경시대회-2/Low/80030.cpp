/*
서로 다른 소수들의 합
https://43.200.211.173/contest/18/problem/80030
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q;
vector<int>* v;
int isprime(int num)
{
	for (p = 2; p < num; p++)
		if (num % p == 0)
			return false;
	return true;
}
int push_primes(int until, vector<int>* vec)
{
	for (i = 2; i < until; i++)
	{
		if (isprime(i))
			vec->push_back(i);
	}
}
int main()
{
	cin >> n >> k;
	v = new vector<int>[k];
	push_primes(n, &v[0]);
}