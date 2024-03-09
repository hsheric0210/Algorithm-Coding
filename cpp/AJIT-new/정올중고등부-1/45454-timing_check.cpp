#include<bits/stdc++.h>
using namespace std;
int i,j,k,l;
struct S { int i,j; };
S V[3];
int main()
{
	cin>>i>>j>>k;
	V[0]={i,i+9}; V[1]={j,j+6}; V[2]={k,k+3};
	sort(V,V+3,[](S a,S b){return a.i<b.i;});
	if(V[0].j>=V[1].i&&V[1].i+9>=V[2].i)
		cout<<"meet";
	else
		cout<<"cannot";
	return 0;
}