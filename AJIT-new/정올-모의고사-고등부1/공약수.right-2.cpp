#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int i,j,k,l;
ll x, y, z, p, q, r;
// x * y = gcd(x, y) * lcm(x, y)
ll gcd(ll x, ll y) // x=max, y=min
{
	ll a=x, b=y, c;
	while(1)
	{
		c = a % b;
		if (c == 0)
			return b;
		a=b;
		b=c;
	}
	return 0;
}
int main()
{
	cin>>p>>q; // p=gcd, q=lcm
	r=p*q;
	for (x=sqrtl(r); x>0; x--)
	{
		if(r%x==0 && gcd(x, r/x) == p) // is one of the divisors and gcd matches
		{
			cout << x << ' ' << r/x << '\n';
			return 0;
		}
	}
	return 0;
}