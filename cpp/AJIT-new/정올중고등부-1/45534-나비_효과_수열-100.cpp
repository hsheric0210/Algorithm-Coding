#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N;
void f(int n)
{
	if(n==1){cout<<1<<' ';return;}
	if(n==2){cout<<2<<' '<<1<<' ';return;}
	cout<<n<<' '; f(n-1); f(n-2);
}
int main(){cin>>N;f(N);return 0;}