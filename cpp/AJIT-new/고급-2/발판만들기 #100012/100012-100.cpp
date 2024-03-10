#include<bits/stdc++.h>
using namespace std;
struct S {int i, h;};
int N,M,i,j,k,l,p,q,r,H[100005], A[100005];
vector<S>V;
int main()
{
	cin>>N; for(i=1;i<=N;i++) cin>>H[i];
	V.push_back({0,0}); // first padding zero
	H[++N]=0; // last padding zero
	for(i=1;i<=N;i++)
	{
		while(1)
		{
			if(H[i]>=V.back().h) break;
			auto ot=V.back(); // old top
			if(ot.h<=H[i]) break;
			V.pop_back();
			auto nt=V.back(); // new top
			j=ot.h*(i-nt.i-1);
#ifndef ONLINE_JUDGE
			cout<<" lat=("<<H[i]<<'/'<<i<<") ot=("<<ot.h<<'/'<<ot.i<<") nt=("<<nt.h<<'/'<<nt.i<<") cS="<<j<<" mS="<<k<<'\n';
			for(auto o:V)
				cout<<" ("<<o.h<<'/'<<o.i<<')';
			cout<<'\n';
#endif
			k=max(k, j);
		}
#ifndef ONLINE_JUDGE
		cout<<"push ("<<H[i]<<'/'<<i<<")\n";
#endif
		V.push_back({i,H[i]});
	}
	cout<<k;
	return 0;
}