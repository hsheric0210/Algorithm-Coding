#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int i,j,k,l,m,n,o,p,q;
ll a,b,c,d,e;
int main()
{
	cin >> a;
	b=a;
	for (i = 1; i < 64; i++)
	{
		if ((y & (1 << i)) && !(y & (i << (i-1))))
		{
            y = (y & ~(1<<i)) | (~y & (1<<i));//y.flip(i);
			y.flip(i-1);
			int c = 0;
			if (i - 2 > 0)
			{
				for (j = 0; j <= i-2; j++)
					if (y[j]) // count of '1'
						c++;
				for (j = 0; j <= i-2; j++)
					y[j]=0;
				for (j = 0; j < c; j++)
					y[(i-2)-j]=1;
			}
			goto ok;
		}
	}
	y = bitset<64>(0);
	ok:
	
	// upper_closest
	for (i = 1; i < 64; i++)
	{
		if (!z[i] && z[i-1]) // find '01'
		{
			// flip to '10'
			z.flip(i);
			z.flip(i-1);
			
			// shift all trailing bits to the right
			int c = 0;
			if (i - 2 > 0)
			{
				for (j = 0; j <= i-2; j++)
					if (z[j]) // count of '1'
						c++;
				for (j = 0; j <= i-2; j++)
					z[j]=0;
				for (j = 0; j < c; j++)
					z[j]=1;
			}
			goto ok2;
		}
	}
	z = bitset<64>(0);
	ok2:
	
	cout << y.to_ullong() << ' ' << z.to_ullong() << '\n';
	return 0;
}