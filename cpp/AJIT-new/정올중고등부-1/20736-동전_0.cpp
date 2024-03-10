#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,K,A[15];
int main()
{
	cin>>N>>K; for(i=0;i<N;i++) cin>>A[i];
	while(k < K) // '동전' 그리디
	{
		auto x = lower_bound(A,A+N,K-k);
		if(x==A+N)x--; // prevent OOB
		if (*x > K-k) x--; // prevent greater-than
		if (*x==0)break;
		k+=*x;
		j++;
	}
	cout<<j;
	return 0;
}