#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N;
double A,B,C;
int main()
{
	cin>>N;
	for(i=1;i<=N;i++)
	{
		cin>>A;
		if(i==1||B<1.0)B=A;else B*=A;
		if(B>C)C=B;
	}
	cout<<fixed<<setprecision(3)<<C;
	return 0;
}