#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

#define DQ_TYPE deque<pair<int, int>>
#define MAP_TYPE unordered_map<int, int>

int Y = -1;

int try_push(DQ_TYPE *dq, MAP_TYPE *m, int idx, int val)
{
    auto fnd = m->find(val);
    if (val > Y || fnd != m->end() && fnd->second <= idx) // 이미 더 나은 값이 추가된 적이 있거나, val이 목표치 Y보다 클 경우, 추가 취소
        return 0;
    dq->push_back(make_pair(idx, val));
    m->insert(make_pair(val, idx));
    return 1;
}

int solution(int x, int y, int n) {
    Y = y;
    DQ_TYPE dq;
    MAP_TYPE m;
    
    // BFS
    try_push(&dq, &m, 0, x);
    while(!dq.empty())
    {
        auto fr = dq.front();
        dq.pop_front();
        try_push(&dq, &m, fr.first + 1, fr.second + n);
        try_push(&dq, &m, fr.first + 1, fr.second * 2);
        try_push(&dq, &m, fr.first + 1, fr.second * 3);
    }
    
    auto fnd = m.find(y);
    if (fnd == m.end())
        return -1;
    return fnd->second;
}