#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, int>visited;

int solution(int storey) {
    deque<pair<int, int>>dq;
    dq.push_back(make_pair(storey, 0)); // (pos, depth)
    visited[storey] = 1;
    int minstone = -1;
    while(!dq.empty())
    {
        auto fr = dq.front();
        dq.pop_front();
        if (fr.first == 0)
        {
            minstone = fr.second;
            break;
        }
        for(int i = 0; i <= 8; i++)
        {
            int a = fr.first+(int)pow(10, i), b = fr.first-(int)pow(10, i);
            //if (a > storey*2) break; // 최적화 1
            if (visited.find(a) == visited.end() || !visited[a])
            {
                dq.push_back(make_pair(a, fr.second + 1));
                visited[a] = 1;
            }
            //if (b <= 0) break; // 최적화 2
            if (visited.find(b) == visited.end() || !visited[b])
            {
                dq.push_back(make_pair(b, fr.second + 1));
                visited[b] = 1;
            }
        }
    }
    return minstone;
}