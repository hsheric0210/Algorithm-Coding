#include<bits/stdc++.h>
using namespace std;
int N,K,i,j,k,l,m,n,o,p,q,r;
deque<int>V;
int main()
{
	cin>>N>>K;
	for(i=1;i<=N;i++) V.push_back(i);
	cout << '<';
	for(i=0, j=0;i<N;i++)
	{
		j = (j + K - 1) % V.size();
		cout << V[j];
		V.erase(V.begin() + j);
		if (i < N-1)
			cout << ", ";
	}
	cout << '>';
	return 0;
}