#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int i,j,k,l,m,n,o,p,q,r,s,t,u,v;
ll gcd, lcm, x, y, z;
int *erastones(ll n) // if arr[n] == 0 then, n is prime.
{
	int *arr = new int[(int)n+1]{0};
	for (i = 2; i <= (sqrt(n)+1); i++)
	{
		for (j = i*2; j <= n; j+=i)
		{
			arr[j] = 1;
		}
	}
	return arr;
}
int main()
{
	cin >> gcd >> lcm;
	x = lcm / gcd;
	cout << "begin erastones\n";
	int* era = erastones(x);
	vector<int> primes;
	for (i = 2; i <= x; i++)
	{
		if (!era[i])
		{
			primes.push_back(i);
		}
	}
	cout << "begin primefactor\n";
	vector<int> divisors;
	for (auto a = primes.begin(); a != primes.end(); a++)
	{
		if (x % *a == 0)
			divisors.push_back(*a);
	}
	
	int alpha = divisors[divisors.size() - 1];
	cout << "alpha=" << alpha << '\n';
	int beta = x / alpha;
	ll a = alpha * gcd;
	ll b = beta * gcd;
	cout << a << ' ' << b << '\n';
	return 0;
}