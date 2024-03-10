#include<bits/stdc++.h>
using namespace std;
int N,i,j,k,H[100005];
struct S {int i, h;}; vector<S>V;
int main()
{
	cin>>N; for(i=1;i<=N;i++) cin>>H[i];
	V.push_back({0,0});	H[++N]=0;
	for(i=1;i<=N;i++)
	{
		while(1)
		{
			auto ot=V.back();
			if(ot.h<=H[i]) break;
			V.pop_back();
			auto nt=V.back();
			k=max(k,ot.h*(i-nt.i-1));
		}
		V.push_back({i,H[i]});
	}
	cout<<k;
	return 0;
}