#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,S,A[25],D[25][25];
int main()
{
	cin>>N>>S; for(i=1;i<=N;i++)cin>>A[i];
	sort(A+1, A+N+1);
	for(i=1;i<=N;i++)D[i][i]=A[i];
	for(i=1;i<=N;i++)
	{
		for(j=i;j>0;j--)
		{
#ifndef ONLINE_JUDGE
			cout<<j<<','<<i<<'\n';
#endif
			if(i>j)D[j][i]=D[j][i-1]+D[i][i];
			if(D[j][i]==S)l++;
		}
	}
	
#ifndef ONLINE_JUDGE
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++) cout<<D[j][i]<<' ';
		cout<<'\n';
	}
#endif
	cout<<l;
	return 0;
}