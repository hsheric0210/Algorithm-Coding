#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int i,j,k,l;
ll gcd, lcm, x, y, z;
ll getGCD(ll a, ll b)
{
	ll alpha=0, beta=a, gamma=b;
	while(1)
	{
		alpha = beta % gamma;
		if (alpha == 0)
			return gamma;
		beta = gamma;
		gamma = alpha;
	}
	return 1;
}
int main()
{
	cin >> gcd >> lcm;
	x = gcd * lcm;
	y = sqrtl(x);
	for (z = y; z > 0; z--)
	{
		ll mod = x % z;
		if (mod == 0)
		{
			ll gcd2 = getGCD(z, x / z);
			//cout << "x mod z = 0 @ z = " << z << " and x/z=" << (x/z) << " -> gcd(z, x/z)=" << gcd2 << '\n';
			if (gcd2 == gcd)
			{
				cout << z << ' ' << x/z << '\n';
				return 0;
			}
		}	
	}
	return 0;
}