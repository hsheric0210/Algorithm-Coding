/*
SCV 자원채취
https://43.200.211.173/contest/17/problem/80024
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> q;
bool* arr;
int* M; // maxMap
int* bt; // backtracking
bool* vst; // visited
int n;
int pk(int x, int y){	return x + y * n;}
void upk(int p, int* x, int* y)
{
	*x = p % n;
	*y = p / n;
}
void cnp(int prv, int dir) // Check & Push
{
	int x, y; upk(prv, &x, &y);
	if (dir) x++; else y++;
	if (x < 0 || x >= n || y < 0 || y >= n) // oob
		return;
	int cur = pk(x, y);
	int v = M[prv] + arr[cur];
	if (v > M[cur] || M[cur] == 0)
	{
		M[cur] = v;
		bt[cur] = (prv | (dir << 24));
	}
	if (!vst[cur])
	{
		q.push_back(cur);
		vst[cur] = 1;
	}
}
int main()
{
	cin >> n;
	arr = new bool[n * n]{ 0 };
	vst = new bool[n * n]{ 0 };
	M = new int[n * n]{ 0 };
	bt = new int[n * n]{ 0 };
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			bool b; cin >> b; arr[pk(x, y)] = b;
		}
	// bfs
	q.push_back(0); // push (0, 0)
	M[0] = arr[0];
	while (!q.empty())
	{
		int fr = q.front();
		q.pop_front();
		int x, y;
		upk(fr, &x, &y);
		cnp(fr, 0);
		cnp(fr, 1);
	}

	// backtrack the max valued chain
	int Me = 0, pp = 0;
	for (int pak = n * n - 1; pak > 0; pak--)
		if (M[pak] > Me)
		{
			Me = M[pp = pak];
		}
	cout << Me << endl;
	deque<char> stk;
	do
	{
		int prev = bt[pp];
		pp = prev & 0xFFFFFF; // drop dir
		stk.push_front((prev >> 24) ? 'R' : 'D');
	} while (pp != 0);

	// print backtrack result
	while (!stk.empty())
	{
		cout << stk.front() << endl;
		stk.pop_front();
	}
}