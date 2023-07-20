// 틀린 이유: 최적화 실패
// 1. 범위 Merge 작업 시, 이전까지 검사했던 모든 범위를 p에 저장하고, 새로운 범위를 추가할 때마다 p 전체를 홇음 -> 시간복잡도 O(n^3)
// 2. 새로운 Struct를 정의하거나, bit-joining (2개의 int를 1개의 long으로 합치기) 기법을 사용하지 않고 vector<int>를 그대로 사용함에서 발생하는 오버헤드

#include <string>
#include <vector>
#include <queue>
#include<iostream>

using namespace std;

struct c{
    bool operator()(vector<int>a,vector<int>b)
    {
        return a[0]==b[0]?a[1]>b[1]:a[0]>b[0];
    }
};

bool intersect(vector<int>a, vector<int>b)
{
    int x = max(a[0],b[0]), y = min(a[1],b[1]);
    //cout<<"X="<<x<<" Y="<<y<<'\n';
    return x<y;
}

int solution(vector<vector<int>> targets) {
    priority_queue<vector<int>, vector<vector<int>>, c>q;
    for(vector<int>v:targets) q.push(v);
    
    int answer = 0;
    while(!q.empty())
    {
        vector<vector<int>>p;
        while(!q.empty())
        {
            auto f = q.top();
            q.pop();
            if(q.empty())
                break;
            bool intrs = true;
            p.push_back(f);
            for(auto x:p)
                if (!intersect(q.top(), x))
                {
                    intrs=false;
                    break;
                }
            if (!intrs)
            {
                //cout<<"not int " << f[0] << ' ' << f[1] << " bet " << q.top()[0] << ' ' << q.top()[1] << '\n';
                break;
            }
        }
        answer++;
    }
    return answer;
}