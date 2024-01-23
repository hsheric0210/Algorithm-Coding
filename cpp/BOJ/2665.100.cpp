// Olympiad > 한국정보올림피아드 > KOI 1997 > 고등부 2번
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <deque>
using namespace std;
struct pos {
	int x, y;
};
int N, i, j, k, l, M[55][55], V[55][55];
deque<pos>next_startpoint;
char ch;
int push(deque<pos>* q, int x, int y)
{
	if (x <= 0 || y <= 0 || x > N || y > N || V[x][y])
	{
		return 0; // bound & visited check
	}
	V[x][y] = 1;

	if (!M[x][y])
	{
		next_startpoint.push_back({ x,y }); // 다음 BFS 루프에서 탐색을 시작할 지점
		return 0;
	}

	q->push_back({ x,y });
	return x == N && y == N;
}
int bfs(int x, int y)
{
	deque<pos>q;
	q.push_back({ x,y });
	V[x][y] = 1;
	while (!q.empty())
	{
		pos top = q.front();
		q.pop_front();
		int tx = top.x, ty = top.y, v = 0;
		v |= push(&q, tx + 1, ty);
		v |= push(&q, tx - 1, ty);
		v |= push(&q, tx, ty + 1);
		v |= push(&q, tx, ty - 1);
		if (v) {
			return 1;
		}
	}
	return 0;
}
int main(int argc, char** argv) {
	cin >> N;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) {
		cin >> ch;
		M[i][j] = ch == '1';
	}

	next_startpoint.push_back({ 1, 1 });
	for (i = 0;; i++)
	{
		if (next_startpoint.empty()) break; // failed
		deque<pos>begin2 = next_startpoint; // copy
		next_startpoint.clear();
		for (pos p : begin2)
		{
			if (bfs(p.x, p.y))
				goto x; // we found the goal
		}
	}
	x:
	cout << i;
	return 0;
}