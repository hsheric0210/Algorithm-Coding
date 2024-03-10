#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int i,j,k,l,m,n,p;
ll gcd, lcm, x, y, z;
int *erastones(ll a)
{
	int *arr = new int[a+1]{0};
	for (i = 2; i <= (int)sqrt((int)a)+1; i++)
		for (j = i * 2; j <= a; j+=i)
			arr[j] = 1;
	return arr;
}
int main()
{
	cin >> gcd >> lcm;
	x = gcd * lcm;
	cout << "Erastones begin\n";
	int *era = erastones(x); // hope not to overflow
	vector<int> primes;
	for (i = 2; i <= x; i++)
		if (!era[i])
			primes.push_back(i);
	cout << "Prime-factor begin\n";
	vector<int> divisors;
	for (auto a = primes.begin(); a != primes.end(); a++)
	{
		if (x % (ll)(*a) == 0)
			divisors.push_back(*a);
	}
	cout << divisors.back() * gcd << ' ' << x / (divisors.back() * gcd) << '\n';
	return 0;
}