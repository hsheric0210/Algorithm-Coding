#include <string>
#include <vector>
#include <queue>
#include<cmath>
#include<iostream>

using namespace std;
typedef unsigned long long ll;
struct range { // using struct is much faster than using vector<int>'s
    int lower,upper;
};
struct c{
    bool operator()(range&a,range&b)
    {
        return a.lower==b.lower?a.upper>b.upper:a.lower>b.lower;
    }
};

range intersect(range a, range b)
{
    return { max(a.lower,b.lower), min(a.upper,b.upper) };
}

int solution(vector<vector<int>> targets) {
    priority_queue<range, vector<range>, c>q;
    for(vector<int>v:targets) q.push({v[0],v[1]});

    // O(n^3) ...
    int answer = 0;
    while(!q.empty()) // outer iteration: through all regions
    {
        range groupInters = { 0, 100000000 }; // initial range
        
        while(!q.empty()) // inner iterations: group-merge iteration
        {
            range f = q.top();
            q.pop();
            if(q.empty())
                break;
            groupInters = intersect(groupInters, f);
            
            // 이전에 검사한 (모든)범위들의 교집합 부분과 접하는 부분이 있는지 검사.
            auto v = intersect(groupInters, q.top());
            if (v.lower < v.upper)
            {
                groupInters = v;
            }
            else
            {
                break;
            }
        }
        answer++;
    }
    return answer;
}