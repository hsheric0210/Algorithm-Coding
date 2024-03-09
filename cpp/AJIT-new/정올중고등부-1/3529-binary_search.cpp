#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,S,A[1000005];
int main()
{
	cin>>N>>S;
	for(i=0;i<N;i++)cin>>A[i];
	auto p=lower_bound(A,A+N,S);
	if(p==A+N||*p!=S)
		cout<<-1;
	else
		cout<<p-A+1;
	return 0;
}