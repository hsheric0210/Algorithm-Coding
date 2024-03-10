#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,m,n,o,p,q,a,b,N;
int main()
{
	cin>>N;
	for(i=p=q=a=b=1;i<=N;i++)
	{
		cin>>j;
		// 놀랍게도 이것은 DP이다.
		if(i==1){k=j;l=j;continue;}//init
		if(k>0){k+=j;q=i;}//accumulate
		else{k=j;p=q=i;}//reset
		if(k>l){l=k;a=p;b=q;}//max
	}
	cout<<a<<' '<<b<<' '<<l;
	return 0;
}