#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,n,m,t,p,q,mx,s, cx,cy;
typedef struct _a{
	int x,y;
}a;
vector<a>A;
void chk(int x,int y)
{
	s=0;
	for(auto a:A)
		if (abs(a.x-x) <= k/2 && abs(a.y-y) <= k/2)
			s++;
	if(s>mx)
	{
		mx=s;
		cx = x;
		cy = y;
	}
}
int main()
{
	cin>>n>>m>>t>>k;
	for(i=0;i<t;i++)
	{
		cin>>p>>q;
		A.push_back({p+q,p-q});
	}
	
	for(auto a:A)
	{
		for(auto b:A)
		{
			if ((a.x+b.y+k)%2) // odd
			{
				chk(a.x+k/2-1,b.y+k/2);
				chk(a.x+k/2,b.y+k/2-1);
				chk(a.x+k/2+1,b.y+k/2);
				chk(a.x+k/2,b.y+k/2+1);
			}
			else
			{
				chk(a.x+k/2,b.y+k/2);
			}
		}
	}
	
    int ox=(cx+cy)/2, oy=cx-ox;
    if(ox>n)ox=n;if(ox<0) ox=0;
    if(oy>m)oy=m;if(oy<0) oy=0;
    cout<<ox<<' '<<oy<<'\n'<<mx<<'\n';
	return 0;
}