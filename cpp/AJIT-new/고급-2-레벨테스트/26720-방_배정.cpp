#include<bits/stdc++.h>
using namespace std;
int N,K,i,j,k,l,m,n,S,Y,C[5][10]; // 1st: M/F, 2nd: grade
int main()
{
	cin>>N>>K;
	for(i=0;i<N;i++)
	{
		cin>>S>>Y;
		C[S][Y]++;
	}
	for(i=0;i<2;i++) for(j=1;j<=6;j++) if (C[i][j]) k += (C[i][j] - 1) / K + 1;
	cout << k;
	return 0;
}