#include<bits/stdc++.h>
using namespace std;

typedef struct P{
    int x,y;
};
int n,m,t,k,mx,cx,cy;
vector<P> points;

//query the contained points of the specified diamond. And update the maximum position if possible.
// fcx, fcy: Coord of the diamond
void query(int fcx, int fcy)
{
    int re=0;//count of contained points
    for(auto P:points)
        if(abs(P.x-fcx)<=k/2 && abs(P.y-fcy)<=k/2) re++;//Manhattan-distance check
    if(mx<re)
    {
        // update max
        mx=re;
        cx=fcx;
        cy=fcy;
    }
}
int main()
{
    int x,a,b,fcx,fcy;
    cin>>n>>m>>t>>k;
    for(x=0;x<t;x++)
    {
        cin>>a>>b;
        points.push_back({a+b,a-b});
    }
    for(auto X:points)
    {
        for(auto Y:points)
        {
            if((X.x+Y.y+k)%2==1)
            {
                // 합이 홀수인 경우 -> 2로 나누면 정수가 나오지 않기에, 해당 실수 점 주변 4개 포인트를 모두 확인
                query(X.x+k/2-1,Y.y+k/2);
                query(X.x+k/2,Y.y+k/2-1);
                query(X.x+k/2+1,Y.y+k/2);
                query(X.x+k/2,Y.y+k/2+1);
            }
            else
            {
                // 합이 짝수인 경우 -> 2로 나누면 정수이기에 해당 점만 확인
                query(X.x+k/2,Y.y+k/2);
            }
        }
    }
    /*
    cx = x+y, cy=x-y
    ox: cx+cy = 2x -> (cx+cy)/2 = x
    oy = cx-ox = (x+y)-x = y
    */
    int ox=(cx+cy)/2, oy=cx-ox; //일차연립방정식 풀기
    if(ox>n)ox=n;if(ox<0) ox=0; //ox=clamp(ox,0,n);
    if(oy>m)oy=m;if(oy<0) oy=0; //oy=clamp(oy,0,m);
    cout<<ox<<' '<<oy<<'\n'<<mx<<'\n';
    return 0;
}