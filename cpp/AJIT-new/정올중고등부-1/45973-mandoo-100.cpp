#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N,T[25]; //3^20=3486784401
int main()
{
	T[0]=1;
	for(i=1;i<=20;i++)T[i]=T[i-1]*3;
	//삼등분 탐색 (세 부분 중 저울 올린 두 쪽 다르면 더 가벼운 곳이 정답, 둘다 동일하면 안 올린 한 쪽이 정답)
	cin>>N;
	auto p=lower_bound(T,T+20,N);
	cout<<p-T;
	return 0;
}