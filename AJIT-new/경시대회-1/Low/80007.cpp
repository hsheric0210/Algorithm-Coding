/*
골드바흐
https://43.200.211.173/contest/17/problem/80007
*/
#include <iostream>
#include <cmath>
using namespace std;
int isPrime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i < n; i++) // exclude 1, n
		if (n % i == 0)
			return false;
	return true;
}
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c; cin >> c;
	int* primes = new int[c] {0};
	for (int a = 2; a <= c; a++)
	{
		if (isPrime(a))
		{
			int b = c - a;
			if (isPrime(b))
			{
				cout << c << " = " << a << " + " << b << endl;
				return 0;
			}
		}
	}
	cout << "Goldbach's conjecture is wrong" << endl;
}