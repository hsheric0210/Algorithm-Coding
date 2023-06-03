// 출처: https://www.acmicpc.net/board/view/42812
#include <iostream>

using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001];
int dp[1001][1001][3];

int solve(int y, int x, int dir) {
    if (y == n && x == m)
        return map[y][x]; // 도착 시 재귀종료

    int& cur = dp[y][x][dir];
    if (cur != -987654321) return cur; // 현재 처리하려는 위치의 dp가 이미 처리되었을 경우 재귀종료

    int left, right, down;
    left = right = down = -987654321;

    // visited-check : 재귀 중 현재 이미 처리된 노드를 재탐색하는 것 방지
    visited[y][x] = true;

    // range-check, visited-check 후 재귀
    if (y >= 1 && y <= n && x - 1 >= 1 && x - 1 <= m && !visited[y][x - 1]) left = solve(y, x - 1, 0);
    if (y >= 1 && y <= n && x + 1 >= 1 && x + 1 <= m && !visited[y][x + 1]) right = solve(y, x + 1, 1);
    if (y + 1 >= 1 && y + 1 <= n && x >= 1 && x <= m && !visited[y + 1][x]) down = solve(y + 1, x, 2);
    visited[y][x] = false;

    cur = map[y][x] + max(down, max(left, right));
    return cur;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];

            // 모든 DP테이블을 초깃값으로 초기화
            dp[i][j][0] = -987654321;
            dp[i][j][1] = -987654321;
            dp[i][j][2] = -987654321;
        }
    }
    // 재귀를 통한 처리 -> 일종의 DFS
    cout << solve(1, 1, 0) << endl;
    return 0;
}