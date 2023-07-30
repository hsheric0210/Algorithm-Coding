#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define HYPOT(x, y) (x)*(x) + (y)*(y)
#define MAX_VAL 0x7FFFFFFF // INT_MAX
// MAX_VAL 값이 충분히 크지 않다면(예시: 10만 정도) 34, 35번 케이스에서 틀립니다.
using namespace std;

int M,N;

int leftCushion(int startX, int startY, int endX, int endY)
{
    if (startY == endY && startX > endX) return MAX_VAL; // 왼쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // y=0 에 대해 대칭이동
    return HYPOT(startX + endX, startY - endY);
}

int rightCushion(int startX, int startY, int endX, int endY)
{
    if (startY == endY && startX < endX) return MAX_VAL; // 오른쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // y=M 에 대해 대칭이동
    return HYPOT(startX - (M * 2 - endX), startY - endY);
}

int upCushion(int startX, int startY, int endX, int endY)
{
    if (startX == endX && startY < endY) return MAX_VAL; // 윗쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // x=0 에 대해 대칭이동
    return HYPOT(startX - endX, startY + endY);
}

int downCushion(int startX, int startY, int endX, int endY)
{
    if (startX == endX && startY > endY) return MAX_VAL; // 아랫쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // x=N 에 대해 대칭이동
    return HYPOT(startX - endX, startY - (N * 2 - endY));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    M = m, N = n;
    vector<int> answer;
    for (auto tc : balls)
    {
        vector<pair<char, int>>tmp;
        tmp.push_back(make_pair('l', leftCushion(startX, startY, tc[0], tc[1])));
        tmp.push_back(make_pair('r', rightCushion(startX, startY, tc[0], tc[1])));
        tmp.push_back(make_pair('u', upCushion(startX, startY, tc[0], tc[1])));
        tmp.push_back(make_pair('d', downCushion(startX, startY, tc[0], tc[1])));
        for (auto vt : tmp)
            cout << "type=" << vt.first << " val=" << vt.second << '\n';
        auto m = min_element(tmp.begin(), tmp.end(), [](auto a, auto b){return a.second < b.second;});
        cout << "best @ tc=[" << tc[0] << ", " << tc[1] << "] is type=" << m->first << " val=" << m->second << '\n';
        answer.push_back(m->second);
    }
    return answer;
}