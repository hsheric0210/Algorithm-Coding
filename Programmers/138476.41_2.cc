#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    deque<pair<int, int>>dq;
    for(int t : tangerine) dq.push_back(make_pair(t, 1));
    sort(dq.begin(),dq.end(), [](auto a, auto b){return a.first < b.first;});

    for (int i = 1; i < dq.size(); i++)
    {
        while (i < dq.size() && dq[i-1].first == dq[i].first)
        {
            dq.erase(dq.begin() + i);
            dq[i-1].second++;
        }
    }
    
    sort(dq.begin(),dq.end(),[](auto a, auto b){return a.second == b.second ? a.first < b.first : a.second > b.second;});
    
    /*
    //dump
    for (auto p : dq)
        cout << '(' << p.first << ", " << p.second << ')';
    cout << '\n';*/
    
    int answer = 0;
    for (int i = 0; i < k; i++)
    {
        if (!dq[answer].second-- && dq.size()-1 > answer)
        {
            answer++;
        }
    }
    return answer+1;
}