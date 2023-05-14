#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll i,j,k,l,x,y,z,p,q,r,N,K;
char c;
vector<ll>A[4];
ll V[4];	
int f(int a, int b)
{
	x = (V[a] + A[a].back()) * V[b];
	y = V[a] * (V[b] + A[b].back());
	return x>y?a:b;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>K;
	for(i=0;i<4;i++)
	{
		cin>>V[i]; A[i].push_back(-1);
	}
	for(i=0;i<N;i++)
	{
		cin>>c>>j; A[c-'A'].push_back(j);
	}
	for(i=0;i<4;i++)
		sort(A[i].begin(), A[i].end());
	for(i=0;i<K;i++)
	{
		p=f(0,1);
		q=f(2,3);
		r=f(p,q);
		cout << (char)(r+'A') << ' ' << A[r].back() << '\n';
		V[r] += A[r].back();
		A[r].pop_back();
	}
	return 0;
}