#include <bits/stdc++.h>
#include <bitset>
using namespace std;
typedef unsigned long long ll;
int i,j,k,l,m,n;
ll a, x, y=0, z=0;
int main()
{
	cin >> a;
	i = bitset<64>(a).count();
	for (x = a-1; x > 0; x--)
	{
		if (bitset<64>(x).count() == i)
		{
			y = x;
			break;
		}
	}
	
	for (x = a+1; x < 0xFFFFFFFFFFFFFFFFL; x++)
	{
		if (bitset<64>(x).count() == i)
		{
			z = x;
			break;
		}
	}
	
	cout << y << ' ' << z << '\n';
}