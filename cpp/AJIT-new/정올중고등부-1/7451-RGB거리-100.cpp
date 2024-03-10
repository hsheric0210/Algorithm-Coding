#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,A[10005][3],D[25][3];
int main()
{
	cin>>N; for(i=1;i<=N;i++)cin>>A[i][0]>>A[i][1]>>A[i][2];
	for(i=1;i<=N;i++)
	{
		D[i][0]=A[i][0]+min(D[i-1][1],D[i-1][2]);
		D[i][1]=A[i][1]+min(D[i-1][0],D[i-1][2]);
		D[i][2]=A[i][2]+min(D[i-1][0],D[i-1][1]);
	}
	cout<<*min_element(D[N],D[N]+3);
	return 0;
}