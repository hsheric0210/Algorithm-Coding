#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int i,j,k,l,m,n,o,p,q;
ll a,b,c,d,e;
bitset<64> x,y,z;
int sol1(ll a, ll* oa, ll* ob)
{
	ll x, y, z;
	i = bitset<64>(a).count();
	for (x = a-1; x > 0; x--)
	{
		if (bitset<64>(x).count() == i)
		{
			y = x;
			break;
		}
	}
	
	for (x = a+1;; x++)
	{
		if (bitset<64>(x).count() == i)
		{
			z = x;
			break;
		}
	}
	
	*oa = y;
	*ob = z;
	//cout << y << ' ' << z << '\n';
}
int sol2(ll a, ll* oa, ll* ob)
{
	x=y=z = bitset<64>(a);
	for (i = 1; i < 64; i++)
	{
		for (j = 1; i-j >= 0; j++)
		{
			if (y[i] && !y[i-j])
			{
				y[i]=0;
				y[i-j]=1;
				goto ok;
			}
		}
	}
	y = bitset<64>(0);
	ok:
	
	for (i = 0; i < 64; i++)
	{
		for (j = 1; i+j < 64; j++)
		{
			if (z[i] && !z[i+j])
			{
				z[i]=0;
				z[i+j]=1;
				goto ok2;
			}
		}
	}
	z = bitset<64>(0);
	ok2:
	
	//cout << y.to_ullong() << ' ' << z.to_ullong() << '\n';
	*oa = y.to_ullong();
	*ob = y.to_ullong();
	return 0;
}
int main()
{
	for (p = 10; p < 100; p++)
	{
		cout << "sol_1 = bruteforce, sol_2 = intelligence\n";
		cout << "p=" << p << ' ';
		ll m1, m2, M1, M2;
		sol1(p, &m1, &M1);
		sol2(p, &m2, &M2);
		if (m1 == m2)
			cout << "\nmin matches ";
		else
		{
			cout << "\nMIN NOT MATCHES ";
			cout << "\no=" << bitset<16>(p) << " m1=" << bitset<16>(m1) << ", m2=" << bitset<16>(m2) << '\n';
		}
		if (M1 == M2)
			cout << "\nmax matches ";
		else
		{
			cout << "\nMAX NOT MATCHES ";
			cout << "\no=" << bitset<16>(p) << " m1=" << bitset<16>(M1) << ", m2=" << bitset<16>(M2) << '\n';
		}
	}
	return 0;
}