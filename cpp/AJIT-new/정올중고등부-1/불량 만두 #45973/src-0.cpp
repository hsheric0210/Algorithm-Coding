#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull i,j,k,l,N;
int r(ull n)
{
	if(n<=2)return n-1;
	return r(n/3+n%3)+1;
}
int main()
{
	//삼등분 탐색 (세 부분 중 저울 올린 두 쪽 다르면 더 가벼운 곳이 정답, 둘다 동일하면 안 올린 한 쪽이 정답)
	cin>>N; cout<<r(N);
	return 0;
}