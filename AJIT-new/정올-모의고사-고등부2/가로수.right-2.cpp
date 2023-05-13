#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int i,j,k,l,n, p, q;
ll x, y, z;
int A[100005];
int gcd(int x, int y)
{
	int a=max(x, y), b=min(x,y), c;
	while(1)
	{
		c = a % b;
		if (c==0)
			return b;
		a=b;
		b=c;
	}
	return 0;
}
int main()
{
	cin>>n;
	k=0x7fffffff;//int_max
	for (i=0;i<n;i++)
	{
		cin>>A[i];
		if (i>=2)
			k = min(k, gcd(A[i] - A[i-1], A[i-1] - A[i-2]));
	}
	
	for (i=1;i<n;i++)
	{
		l = A[i] - A[i-1];
		p += l / k - 1;
	}
	
	cout<<p<<'\n';
	return 0;
}