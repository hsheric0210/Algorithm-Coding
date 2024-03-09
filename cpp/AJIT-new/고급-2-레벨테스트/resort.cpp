#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,k,l,C[1005],D[1005][1005];
int main()
{
	cin>>N>>M;
	for(i=0;i<M;i++) { cin>>j; C[j]=1; }
	for(i=0;i<=N;i++) for(j=0;j<=N*6;j++) D[i][j]=100000000; D[0][0]=0; // 왜인지는모르겠는데 N*6 저거 N*3처럼 낮게잡으면 BOJ 99%에서 틀리더라
	for(i=1;i<=N;i++)
	{
		for(j=0;j<=i;j++)
		{
			k=D[i][j];
			k=min(k,D[i-1][j]+(!C[i]*10000)); // (1일이용권) i번째 날이 리조트 갈 수 있는 날이면 +10000, 못 가는 날이면 +0
			if(i>=3&&j>=1) k=min(k,D[i-3][j-1]+25000); // (3일이용권) +25000
			if(i>=5&&j>=2) k=min(k,D[i-5][j-2]+37000); // (5일이용권) +37000
			k=min(k,D[i-1][j+3]); // (1일이용권) 쿠폰사용
			D[i][j]=k;
		}
	}
	cout<<*min_element(D[N],D[N]+N);
	return 0;
}