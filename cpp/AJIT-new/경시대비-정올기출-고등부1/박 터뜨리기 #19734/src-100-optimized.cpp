#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int i,j,k,l,N,K,n,p,q,r;
int main()
{
	cin>>N>>K;
	r=1;
	for(i=1;i<K;i++)
		j+=i;
	do
	{

		if(p>0)
		{
			j-=p;
			j+=K;
			r=0;
		}
		n = (N+j)/K;
		if(n<K)//n>K이어야지 n+(n-1)+(n-2)+...+(n-K+1)로 분배 가능
		{
			cout<<-1<<'\n';
			return 0;
		}
	} while((p = (N+j)%K)>0);
	if(n-(K-1)<1)//min bag must have at least one ball
		cout<<-1<<'\n';
	else
		cout<<K-r<<'\n';
	return 0;
}