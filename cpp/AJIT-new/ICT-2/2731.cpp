// ICT-2 : 미로 탐색 - 기초 BFS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<iomanip>
using namespace std;
int i, j, k, l, p, q, r, x, y, z, M, N;
int A[105][105];
typedef struct _a {
	int x, y;
}a;
deque<a>dq;
void avail(a pos, a prev)
{
	if (pos.x < 0 || pos.x >= N || pos.y < 0 || pos.y >= M) return;
	if (A[pos.x][pos.y] == 1) // 1 = visitable, but not visited yet
	{
		A[pos.x][pos.y] = A[prev.x][prev.y] + 1;
		dq.push_back(pos);
	}
}
int main()
{
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (j = 0; j < M; j++)
			A[i][j] = s[j] - '0';
	}

	dq.push_back({ 0,0 });
	while (!dq.empty())
	{
		auto& fr = dq.front();
		dq.pop_front();
		if (fr.x == N - 1 && fr.y == M - 1)
			break;
		avail({ fr.x + 1,fr.y }, fr);
		avail({ fr.x - 1,fr.y }, fr);
		avail({ fr.x,fr.y + 1 }, fr);
		avail({ fr.x,fr.y - 1 }, fr);
	}

//#define DUMP
#ifdef DUMP
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
		{
			cout << setw(3)<< A[i][j] << ' ';
		}
		cout << '\n';
	}
#endif
	cout << A[N - 1][M - 1] << '\n';
	return 0;
}