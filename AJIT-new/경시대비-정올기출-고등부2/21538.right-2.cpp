#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
ll i,j,k,l,t,n,M,N,D,B,T,Tx;
ll x,y,z,p,q,r;
int nCr(ll n, ll r)
{
	// optimizations
	if(r==n)
		return 1;
	if(r>n-r)
		r=n-r;
	if (r == 1)
		return n;
	
	// nPr
	for(j=0,x=1;j<r;j++)
		x*=(n-j);
	// r!
	for(j=1,y=1;j<=r;j++)
		y*=j;
	return x/y; // nCr = nPr / r!
}
int main()
{
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>N>>M>>k>>D;
		T = nCr(M, 2)*N*k + M*M*N*(N-1)/2;
		p = D%T;
		if(p==0&&D/T>0) //T가 D의 인수
			cout<<D<<'\n';
		else if((D-p)/T>0) //D가 T로 
			cout<<D-p<<'\n';
		else
			cout<<-1<<'\n';
	}
	return 0;
}