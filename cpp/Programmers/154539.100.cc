#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int>v(numbers.size());
    deque<pair<int, int>>q;
    for (int i = 0, j = numbers.size(); i < j; i++)
    {
        while (!q.empty() && q.back().second < numbers[i])
        {
            auto bak = q.back();
            q.pop_back();
            v[bak.first] = numbers[i];
        }
        
        if (q.empty() || q.back().second >= numbers[i])
            q.push_back(make_pair(i, numbers[i]));
    }
    
    while(!q.empty())
    {
        auto bak = q.back();
        q.pop_back();
        v[bak.first] = -1;
    }
    
    return v;
}