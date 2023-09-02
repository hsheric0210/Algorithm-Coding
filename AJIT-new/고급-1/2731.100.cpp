/*
문제명: 미로 탐색
교실: 고급-1
난이도: Mid
알고리즘: BFS
*/
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

struct E { int x, y, d; };

char ch;
int N, M, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
char V[105][105];
deque<E>Q;
void push(int x, int y, int d)
{
	if (x <= 0 || y <= 0 || x > N || y > M || V[x][y] == '0') return;
	Q.push_back({ x,y,d });
	V[x][y] = '0'; // mark visited
}
int main()
{
	cin >> N >> M;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			cin >> V[i][j];

	Q.push_back({ 1,1,1 });
	while (!Q.empty())
	{
		auto f = Q.front();
		Q.pop_front();
		if (f.x == N && f.y == M)
		{
			p = f.d;
			break;
		}
		push(f.x + 1, f.y, f.d + 1);
		push(f.x - 1, f.y, f.d + 1);
		push(f.x, f.y + 1, f.d + 1);
		push(f.x, f.y - 1, f.d + 1);
	}
	cout << p;
	return 0;
}