#include<bits/stdc++.h>
using namespace std;
int N,i,j,k,l,m,n,T[60005];
int main()
{
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>m>>n;
		for(j=min(m,n),k=max(m,n);j<k;j++)
			T[j+30000]++;
	}
	cout << *max_element(T, T+60000);
	return 0;
}