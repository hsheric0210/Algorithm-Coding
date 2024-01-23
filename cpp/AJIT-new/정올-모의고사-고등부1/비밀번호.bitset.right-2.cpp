#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int i,j,k,l;
ll x, y, z;
bitset<64>p,q;
int main()
{
	cin>>x;
	p=q=bitset<64>(x);
	for (i = 0;i<63;i++)
	{
		if (!p[i] && p[i+1]) // find 10
		{
			// flip to 01
			p.flip(i);
			p.flip(i+1);
			
			// shift bits to THE LEFT BORDER - count & zero
			l = 0;
			for (j = 0; j < i; j++)
				if (p[j])
				{
					l++; // count
					p.reset(j); // set to zero
				}
			// shift trailing bits to THE LEFT BORDER - set
			for (j = 0;j < l; j++)
				p.set(i-j-1);
			goto fin_1;
		}
	}
	p = bitset<64>(0);
	fin_1:
	
	for (i = 0; i < 63; i++)
	{
		if (q[i] && !q[i+1]) // find 01
		{
			// flip to 10
			q.flip(i);
			q.flip(i+1);
			
			// shift bits to THE LEFT BORDER - count & zero
			l = 0;
			for (j = 0; j < i; j++)
				if (q[j])
				{
					l++;
					q.reset(j);
				}
			// shift bits to THE LEFT BORDER - set
			for (j = 0; j < l; j++)
				q.set(j);
			goto fin_2;
		}
	}
	q = bitset<64>(0);
	fin_2:
	
	cout << p.to_ullong() << ' ' << q.to_ullong() << '\n';
}