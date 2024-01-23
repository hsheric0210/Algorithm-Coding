#include <string>
#include <vector>
#include <algorithm>

#define HYPOT(x, y) (x)*(x) + (y)*(y)
using namespace std;

int M,N;

int leftCushion(int startX, int startY, int endX, int endY)
{
    if (startY == endY && startX > endX) return 100000; // 왼쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // y=0 에 대해 대칭이동
    return HYPOT(startX + endX, startY - endY);
}

int rightCushion(int startX, int startY, int endX, int endY)
{
    if (startY == endY && startX < endX) return 100000; // 오른쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // y=M 에 대해 대칭이동
    return HYPOT(startX - (M * 2 - endX), startY - endY);
}

int upCushion(int startX, int startY, int endX, int endY)
{
    if (startX == endX && startY < endY) return 100000; // 윗쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // x=0 에 대해 대칭이동
    return HYPOT(startX - endX, startY + endY);
}

int downCushion(int startX, int startY, int endX, int endY)
{
    if (startX == endX && startY > endY) return 100000; // 아랫쪽 벽으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황
    // x=N 에 대해 대칭이동
    return HYPOT(startX - endX, startY - (N * 2 - endY));
}

int leftUpCornerCushion(int startX, int startY, int endX, int endY)
{
    if (endX - startX == startY - endY && startX > endX) return 100000; // 왼쪽 위 꼭짓점으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황 (기울기 -1, 시작X > 끝X)
    // x=0, y=0 에 대해 대칭이동
    return HYPOT(startX + endX, startY + endY);
}

int rightUpCornerCushion(int startX, int startY, int endX, int endY)
{
    if (endX - startX == endY - startY && startX < endX) return 100000; // 오른쪽 위 꼭짓점으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황 (기울기 1, 시작X < 끝X)
    // x=0, y=M 에 대해 대칭이동
    return HYPOT(startX - (M * 2 - endX), startY + endY);
}

int leftDownCornerCushion(int startX, int startY, int endX, int endY)
{
    if (endX - startX == endY - startY && startX < endX) return 100000; // 왼쪽 아래 꼭짓점으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황 (기울기 1, 시작X > 끝X)
    // x=N, y=0 에 대해 대칭이동
    return HYPOT(startX + endX, startY - (N * 2 - endY));
}

int rightDownCornerCushion(int startX, int startY, int endX, int endY)
{
    if (endX - startX == endY - startY && startX < endX) return 100000; // 왼쪽 위 꼭짓점으로 쿠션 치면 벽에 맞기 전에 공이 맞는 상황 (기울기 1, 시작X > 끝X)
    // x=N, y=M 에 대해 대칭이동
    return HYPOT(startX - (M * 2 - endX), startY - (N * 2 - endY));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    M = m, N = n;
    vector<int> answer;
    for (auto tc : balls)
    {
        answer.push_back(min({
            leftCushion(startX, startY, tc[0], tc[1]),
            rightCushion(startX, startY, tc[0], tc[1]),
            upCushion(startX, startY, tc[0], tc[1]),
            downCushion(startX, startY, tc[0], tc[1]),
            leftUpCornerCushion(startX, startY, tc[0], tc[1]),
            leftDownCornerCushion(startX, startY, tc[0], tc[1]),
            rightUpCornerCushion(startX, startY, tc[0], tc[1]),
            rightDownCornerCushion(startX, startY, tc[0], tc[1])
        }));
    }
    return answer;
}