#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,N;
deque<int>I;
vector<int>V,R;
int main()
{
	cin>>N; for(i=0;i<N;i++){cin>>j;I.push_back(j);} k=1;
	V.push_back(I.front()); I.pop_front(); R.push_back('S');
	while(!V.empty()||!I.empty())
	{
		if(!V.empty()&&V.back()==k) { R.push_back('X'); V.pop_back(); k++; }
		else if(!I.empty()) { R.push_back('S'); V.push_back(I.front()); I.pop_front(); }
		else { cout<<"IMPOSSIBLE"; return 0; }
	}
	for(char c:R)cout<<c;
	return 0;
}