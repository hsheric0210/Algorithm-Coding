/*
토마토
https://www.acmicpc.net/problem/7576
- Not resolved
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#define pack(x, y) (y * m + x)
using namespace std;
int m, n;
int* arr;
int* visited;
void checkAndPush(deque<int>* q, int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= m || arr[pack(x, y)] == -1 /*encountered obstacle*/ || visited[pack(x, y)] != 0 /*already visited*/)
		return;
	arr[pack(x, y)] = 1;
	q->push_back(pack(x, y));
	visited[pack(x, y)] = 1;
}
int main()
{
	cin >> m >> n;
	arr = new int[m * n]{ 0 };
	visited = new int[m * n]{ 0 };
	deque<int> q;
	for (int v = 0; v < n; v++)
		for (int h = 0; h < m; h++)
		{
			int val; cin >> val;
			arr[pack(h, v)] = val;
			if (val > 0)
			{
				q.push_back(pack(h, v));
			}
		}

	if (q.empty()) // all empty (no mature tomato present)
	{
		cout << -1 << endl;
		return 0;
	}

	int d = 0;
	while (!q.empty())
	{
		// check all mature
		bool brk = 1;
		for (int v = 0; v < n; v++)
			for (int h = 0; h < m; h++)
				if (arr[pack(h, v)] == 0)
					brk = 0;
		if (brk)
			break;

		// copy all elements of q to tmpq
		deque<int> tmpq;
		while (!q.empty())
		{
			tmpq.push_back(q.front());
			q.pop_front();
		}


		// DUMP ARR
		//cout << "v day " << d << " on array v" << endl;
		//for (int v = 0; v < n; v++)
		//{
		//	for (int h = 0; h < m; h++)
		//		cout << arr[pack(h, v)] << " ";
		//	cout << endl;
		//}
		// DUMP ARR END

		// process all elements of tmpq and write to q
		while (!tmpq.empty())
		{
			int front = tmpq.front();
			tmpq.pop_front();
			int frontX = front % m;
			int frontY = front / m;
			checkAndPush(&q, frontX + 1, frontY);
			checkAndPush(&q, frontX - 1, frontY);
			checkAndPush(&q, frontX, frontY + 1);
			checkAndPush(&q, frontX, frontY - 1);
		}
		d++;
	}

	// check any zero exists
	bool failedToFill = 0;
	for (int v = 0; v < n; v++)
		for (int h = 0; h < m; h++)
			if (arr[pack(h, v)] == 0)
				failedToFill = 1;

	if (failedToFill)
		d = -1;
	cout << d << endl;
}