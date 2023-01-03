/*
종이자르기
https://43.200.211.173/contest/17/problem/1779
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;
typedef struct _coord { int x; int y; } coord;
typedef struct _piece {
	int i; int vol; coord bound;
	char* d;
} piece;
int l;
bool tryIntercept(char* table, piece pc, int offset_x, int offset_y)
{
	for (int i = 0; i < pc.bound.y; i++)
	{
		for (int j = 0; j < pc.bound.x; j++)
		{
			if (offset_x + j < 0 || offset_x + j >= l || offset_y + i < 0 || offset_y + i >= l) return false; // Index error
			char src = pc.d[i * pc.bound.x + j];
			int pos = (i + offset_y) * l + j + offset_x;
			if (src == '#' && table[pos] == '.') table[pos] = (char)(pc.i + 1 + '0');
			else if (src != '.' && table[pos] != '.') return false; // Overwritten
		}
	}
	return true;
}
void printTable(char* table)
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
			cout << table[l * i + j];
		cout << endl;
	}
}
int findOptimalInterception(char* table, piece pc, deque<pair<coord, char*>>* workQueue)
{
	int count = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
		{
			char* tcpy = new char[l * l];
			memcpy(tcpy, table, l * l * sizeof(char));
			if (tryIntercept(tcpy, pc, j, i))
			{
				coord cd = { j,i };
				workQueue->push_back(make_pair(cd, tcpy));
				count++;
			}
		}
	return count;
}
int pieceComparator(piece a, piece b)
{
	return a.vol == b.vol ? a.i > b.i : a.vol > b.vol;
}
bool tableComparator(pair<coord, char*> a, pair<coord, char*> b)
{
	return memcmp(a.second, b.second, l * l * sizeof(char)) > 0;
}
int main()
{
	cin >> l;
	piece* pcs = new piece[5];

	// Read pieces
	for (int i = 0; i < 5; i++)
	{
		int n, m; cin >> n >> m;
		char* c = new char[n * m]{ 0 };
		int vol = 0;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				char ch; cin >> ch;
				if (ch == '#')
					vol++;
				c[m * j + k] = ch;
			}
		coord bound = { m, n };
		piece pc = { i, vol, bound, c };
		pcs[i] = pc;
	}

	// Sort pieces by volume and id
	sort(pcs, pcs + 5, pieceComparator);

	// Prepare initial table
	char* initialTable = new char[l * l]{ 0 };
	for (int i = 0; i < l * l; i++) initialTable[i] = '.'; // replacement of strset

	deque<pair<coord, char*>> workQueue;
	findOptimalInterception(initialTable, pcs[0], &workQueue);
	int pieceIndex = 1;
	while (!workQueue.empty())
	{
		// workQueue를 완전히 비운 후 다음에 piece에 대해 작업을 시작하기 위해서는
		// workQueue를 다른 곳으로 복사한 후 처리해야 한다
		deque<pair<coord, char*>> workQueueCopy;
		while (!workQueue.empty())
		{
			workQueueCopy.push_back(workQueue.front());
			workQueue.pop_front();
		}

		while (!workQueueCopy.empty())
		{
			if (pieceIndex == 5)
			{
				// 5번째 piece까지 모두 처리한 후
				printTable(max_element(workQueueCopy.begin(), workQueueCopy.end(), tableComparator)->second);
				return 0;
			}
			else
			{
				pair<coord, char*> top = workQueueCopy.front();
				workQueueCopy.pop_front();
				findOptimalInterception(top.second, pcs[pieceIndex], &workQueue);
			}
		}
		pieceIndex++;
	}

	cout << "gg" << endl;
}
