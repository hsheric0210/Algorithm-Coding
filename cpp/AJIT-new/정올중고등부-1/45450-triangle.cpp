#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N;
int main()
{
	cin>>N;
	if(N<3){cout<<0;return 0;}
	for(i=1;i<=N/3;i++)
	{
		for(j=i;j<=(N-i)/2;j++)
		{
			if(i+j<=N-i-j)continue; //삼각부등식
			l++;
		}
	}
	cout<<l;
	return 0;
}