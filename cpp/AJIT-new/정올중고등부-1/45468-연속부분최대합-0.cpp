#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,A[105];
struct S{int i,j,k,l;};
S D[105];
int main()
{
	cin>>N;for(i=1;i<=N;i++)cin>>A[i];
	D[0]={-1,-1,-1,-1};
	for(i=1;i<=N;i++){l=max(D[i-1].i,0)+A[i]; D[i]={l, D[i-1].i<0?i:D[i-1].j, D[i-1].l<l?i:D[i-1].k, max(D[i-1].l,l)};};
	cout<<D[N].j<<' '<<D[N].k<<' '<<D[N].l;
	return 0;
}