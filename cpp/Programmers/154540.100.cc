#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

struct mvmt { int x,y; };

int xl, yl;
int map[105][105], visited[105][105];

void push(deque<mvmt>*q,int x,int y)
{
    if (x < 0 || x >= xl || y < 0 || y >= yl || visited[x][y] || map[x][y] == -1)
        return;
    q->push_back({x,y});
    visited[x][y] = 1;
}

int bfs(int x, int y)
{
    int cnt = 0;
    deque<mvmt>q;
    push(&q,x,y);
    while(!q.empty())
    {
        auto fr = q.front();
        q.pop_front();
        if (map[fr.x][fr.y]>0)
            cnt += map[fr.x][fr.y];
        push(&q,fr.x+1,fr.y);
        push(&q,fr.x,fr.y+1);
        push(&q,fr.x-1,fr.y);
        push(&q,fr.x,fr.y-1);
    }
    return cnt;
}

vector<int> solution(vector<string> maps) {
    xl = maps.size();
    for (int i = 0; i < xl; i++)
    {
        yl = maps[i].length();
        for (int j = 0; j < yl; j++)
        {
            int v = -1;
            if (maps[i][j] != 'X')
                v = maps[i][j] - '0';
            map[i][j] = v;
        }
    }
    
    vector<int>v;
    for(int i = 0; i < xl; i++)
        for (int j = 0; j < yl; j++)
        {
            int val = bfs(i,j);
            if (val > 0)
                v.push_back(val);
        }
    if (v.empty())
        v.push_back(-1);
    sort(v.begin(), v.end());
    return v;
}