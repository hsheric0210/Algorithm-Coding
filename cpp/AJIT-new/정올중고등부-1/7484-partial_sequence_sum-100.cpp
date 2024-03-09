#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,m,n,N,S,A[25],D[25][25];
int main()
{
	cin>>N>>S; for(i=0;i<N;i++)cin>>A[i];
	sort(A, A+N);
	for(i=1;i<(1<<N);i++) // 1<<N = 2^N
	{
		// i는 인덱스임과 동시에 비트마스크로 변환 시 현재 i 번째 조합에서 가능한 부분집합에 포함되는 원소들을 나타냄.
		// https://stackoverflow.com/a/6781854
		for(j=i,k=l=0;j;(j>>=1),k++) if(j&1) l+=A[k];
		if(l==S)m++;
	}
	cout<<m;
	return 0;
}