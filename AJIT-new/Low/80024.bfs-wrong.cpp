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
int* maxs;
int* chains;
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
	int newVal = maxs[prev] + arr[curr];
	if (newVal >= maxs[curr])
	{
		maxs[curr] = newVal;
		q.push_back(curr);
		chains[curr] = (prev | (dir << 24));
	}
}
int main()
{
	cin >> n;
	arr = new bool[n * n]{ 0 };
	maxs = new int[n * n]{ 0 };
	chains = new int[n * n]{ 0 };
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			bool b; cin >> b; arr[pack(x, y)] = b;
		}
	// bfs
	q.push_back(0); // push (0, 0)
	while (!q.empty())
	{
		int fr = q.front();
		q.pop_front();
		int x, y;
		unpack(fr, &x, &y);
		check_and_push(fr, 0);
		check_and_push(fr, 1);
	}

#ifdef DBG
	cout << "max_map: " << endl;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << maxs[pack(x, y)] << ' ';
		}
		cout << endl;
	}

	cout << "chain_map: (<prevChain>)=<dir>" << endl;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			int chain = chainConnection[pack(x, y)];
			int prev = chain & 0xFFFFFF;
			int _x, _y; unpack(prev, &_x, &_y);
			char dir = (chain >> 24) ? 'R' : 'D';
			cout << '(' << _x << ", " << _y << ")=" << dir << ' ';
		}
		cout << endl;
	}
#endif

	// backtrack the max valued chain
	int* maxp = max_element(maxs, maxs + n * n);
	cout << *maxp << endl;
	int ppos = maxp - maxs;
	deque<char> stack;
	do
	{
		int prev = chains[ppos];
		ppos = prev & 0xFFFFFF; // drop dir
		stack.push_front((prev >> 24) ? 'R' : 'D');
	} while (ppos != 0);

	// print backtrack result
	while (!stack.empty())
	{
		cout << stack.front() << endl;
		stack.pop_front();
	}
}