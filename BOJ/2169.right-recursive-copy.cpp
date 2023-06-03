// ��ó: https://www.acmicpc.net/board/view/42812
#include <iostream>

using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001];
int dp[1001][1001][3];

int solve(int y, int x, int dir) {
    if (y == n && x == m)
        return map[y][x]; // ���� �� �������

    int& cur = dp[y][x][dir];
    if (cur != -987654321) return cur; // ���� ó���Ϸ��� ��ġ�� dp�� �̹� ó���Ǿ��� ��� �������

    int left, right, down;
    left = right = down = -987654321;

    // visited-check : ��� �� ���� �̹� ó���� ��带 ��Ž���ϴ� �� ����
    visited[y][x] = true;

    // range-check, visited-check �� ���
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

            // ��� DP���̺��� �ʱ갪���� �ʱ�ȭ
            dp[i][j][0] = -987654321;
            dp[i][j][1] = -987654321;
            dp[i][j][2] = -987654321;
        }
    }
    // ��͸� ���� ó�� -> ������ DFS
    cout << solve(1, 1, 0) << endl;
    return 0;
}