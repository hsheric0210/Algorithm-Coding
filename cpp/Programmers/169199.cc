#include <string>
#include <vector>
#include <deque>

using namespace std;

struct pos {
    int x, y, depth;
};
deque<pos>q;

int xSize, ySize;
int map[105][105];
int visited[105][105];

void trypush(pos op, pos np)
{
    if (op.x == np.x && op.y == np.y || visited[np.y][np.x]) return;
    q.push_back(np);
    visited[np.y][np.x] = 1;
}

void left(pos p)
{
    int x;
    for (x = p.x; x > 0; x--)
        if (map[p.y][x-1])
            break;
    trypush(p, {x, p.y, p.depth+1});
}

void right(pos p)
{
    int x;
    for (x = p.x; x < xSize - 1; x++)
        if (map[p.y][x+1])
            break;
    trypush(p, {x, p.y, p.depth+1});
}

void up(pos p)
{
    int y;
    for (y = p.y; y > 0; y--)
        if (map[y-1][p.x])
            break;
    trypush(p, {p.x, y, p.depth+1});
}

void down(pos p)
{
    int y;
    for (y = p.y; y < ySize - 1; y++)
        if (map[y+1][p.x])
            break;
    trypush(p, {p.x, y, p.depth+1});
}

// BFS
int solution(vector<string> board) {
    int initX = 0, initY = 0, destX = 0, destY = 0;
    // push the map to array
    ySize = board.size();
    xSize = board[0].length();
    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            if (board[y][x] == 'R')
            {
                initX = x;
                initY = y;
            }
            if (board[y][x] == 'G')
            {
                destX = x;
                destY = y;
            }
            map[y][x] = board[y][x] == 'D'; // 지나갈 수 있으면 0, 없으면 1
        }
    }
    
    q.push_back({initX, initY, 0});
    int depth = -1;
    while(!q.empty())
    {
        auto f = q.front();
        q.pop_front();
        if (f.x == destX && f.y == destY)
        {
            depth = f.depth;
            break;
        }
        left(f);
        right(f);
        up(f);
        down(f);
    }
    
    return depth;
}