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