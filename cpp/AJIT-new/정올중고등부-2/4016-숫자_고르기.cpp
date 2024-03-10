#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,A[105],B[105]; // A: adjacent array, B: temporary array
int main()
{
	cin>>N;
	for(i=1;i<=N;i++){ cin>>A[i]; }
	while(1)
	{
		fill(B,B+N+1,0);
		for(i=1;i<=N;i++) if(A[i]>0)B[A[i]]=1; // B[n] : node #n has a valid income-node
		for(i=1,k=0;i<=N;i++)
			if(A[i]>0&&!B[i]) // node A[i] is valid but there are no valid income-nodes for this node
			{
				A[i]=-1; // drop it (change the value to -1)
				k=1; // k=1 : we just dropped any node
			}
		if(!k)break; // exit the loop if there are no nodes to drop
	}
	for(i=1,j=0;i<=N;i++) if(A[i]>0) j++;
	cout<<j<<'\n';
	for(i=1;i<=N;i++) if(A[i]>0) cout<<i<<'\n';
	return 0;
}
