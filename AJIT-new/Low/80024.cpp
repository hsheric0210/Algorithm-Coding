/*
SCV �ڿ�ä��
https://43.200.211.173/contest/17/problem/80024
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> q;
bool* arr;
int* maxMap;
int* backtrack;
bool* visited;
int n;
int pack(int x, int y)
{
	return x + y * n;
}
void unpack(int packed, int* x, int* y)
{
	*x = packed % n;
	*y = packed / n;
}
void check_and_push(int prev, int dir)
{
	int x, y; unpack(prev, &x, &y);
	if (dir) x++; else y++;
	if (x < 0 || x >= n || y < 0 || y >= n) // oob
		return;
	int curr = pack(x, y);
	int newVal = maxMap[prev] + arr[curr];
	if (newVal > maxMap[curr] || maxMap[curr] == 0)
	{
		maxMap[curr] = newVal;
		backtrack[curr] = (prev | (dir << 24));
	}
	if (!visited[curr])
	{
		q.push_back(curr);
		visited[curr] = 1;
	}
}
int main()
{
	cin >> n;
	arr = new bool[n * n]{ 0 };
	visited = new bool[n * n]{ 0 };
	maxMap = new int[n * n]{ 0 };
	backtrack = new int[n * n]{ 0 };
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			bool b; cin >> b; arr[pack(x, y)] = b;
		}
	// bfs
	q.push_back(0); // push (0, 0)
	maxMap[0] = arr[0];
	while (!q.empty())
	{
		int fr = q.front();
		q.pop_front();
		int x, y;
		unpack(fr, &x, &y);
		check_and_push(fr, 0);
		check_and_push(fr, 1);
	}

	// backtrack the max valued chain
	int maxelm = 0, prevPos = 0;
	for (int pak = n * n - 1; pak > 0; pak--)
		if (maxMap[pak] > maxelm)
		{
			maxelm = maxMap[prevPos = pak];
		}
	cout << maxelm << endl;
	deque<char> stack;
	do
	{
		int prev = backtrack[prevPos];
		prevPos = prev & 0xFFFFFF; // drop dir
		stack.push_front((prev >> 24) ? 'R' : 'D');
	} while (prevPos != 0);

	// print backtrack result
	while (!stack.empty())
	{
		cout << stack.front() << endl;
		stack.pop_front();
	}
}