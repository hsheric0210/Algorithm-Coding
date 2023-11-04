#include <string>
#include <vector>
#include <deque>
#include <iostream>

struct mvmt {
    int x, y, depth;
};

using namespace std;

int xl, yl;
char map[105][105];
int visited_1[105][105];
int visited_2[105][105];

void push(deque<mvmt> *dq, int visited[105][105], int x, int y, int depth)
{
    if (x < 0 || x >= xl || y < 0 || y >= yl || visited[x][y] || map[x][y] == 'X')
        return;
    dq->push_back({x, y, depth});
    visited[x][y] = 1;
}

int solution(vector<string> maps) {
    int answer = -1;
    
    int sx = -1, sy = -1, i, j;
    for (i = 0, xl = maps.size(); i < xl; i++)
    {
        for (j = 0, yl = maps[i].length(); j < yl; j++)
        {
            map[i][j] = maps[i][j];
            cout << maps[i][j];
            if (maps[i][j] == 'S') { sx = i; sy = j; }
        }
        cout << '\n';
    }
    
    int lev_cost = -1, lev_x = -1, lev_y = -1, end_cost = -1;
    deque<mvmt>dq;
    dq.push_back({sx, sy, 0});
    while(!dq.empty())
    {
        auto fr = dq.front();
        dq.pop_front();
        if (map[fr.x][fr.y] == 'L')
        {
            lev_x = fr.x;
            lev_y = fr.y;
            lev_cost = fr.depth;
            cout << "found lever @ " << fr.x << ", " << fr.y << " w/ cost " << fr.depth << '\n';
            break;
        }
        push(&dq, visited_1, fr.x+1, fr.y, fr.depth+1);
        push(&dq, visited_1, fr.x, fr.y+1, fr.depth+1);
        push(&dq, visited_1, fr.x-1, fr.y, fr.depth+1);
        push(&dq, visited_1, fr.x, fr.y-1, fr.depth+1);
    }
    
    dq.clear();

    dq.push_back({lev_x, lev_y, 0});
    while(!dq.empty())
    {
        auto fr = dq.front();
        dq.pop_front();
        if (map[fr.x][fr.y] == 'E')
        {
            end_cost = fr.depth;
            cout << "found end w/ cost " << fr.depth << '\n';
            break;
        }
        push(&dq, visited_2, fr.x+1, fr.y, fr.depth+1);
        push(&dq, visited_2, fr.x, fr.y+1, fr.depth+1);
        push(&dq, visited_2, fr.x-1, fr.y, fr.depth+1);
        push(&dq, visited_2, fr.x, fr.y-1, fr.depth+1);
    }
    
    if (lev_cost == -1 || end_cost == -1)
        return -1;
    return lev_cost + end_cost;
}