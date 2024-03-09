#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,D[50];
int main()
{
	cin>>N;
	D[0]=1;D[1]=1;D[2]=2;
	for(i=3;i<=N;i++)D[i]=D[i-1]+D[i-2]+D[i-3];
	cout<<D[N];
	return 0;
}