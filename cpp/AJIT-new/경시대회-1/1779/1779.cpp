/*
종이자르기
https://43.200.211.173/contest/17/problem/1779
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
typedef struct _coord { int x; int y; } coord;
typedef struct _piece {
	int i; int vol; coord bound;
	char* d;
} piece;
int l;
//#define DBGMSG
bool tryIntercept(char* tbl, piece pc, int offx, int offy)
{
	for (int i = 0; i < pc.bound.y; i++)
	{
		for (int j = 0; j < pc.bound.x; j++)
		{
			if (offx + j < 0 || offx + j >= l || offy + i < 0 || offy + i >= l)
			{
#ifdef DBGMSG
				cout << "index-err" << endl;
#endif
				return false;
			}
			char src = pc.d[i * pc.bound.x + j];
			int pos = (i + offy) * l + j + offx;
			char dst = tbl[pos];
			if (src == '#' && dst == '.') // src filled & dst empty or src empty
				tbl[pos] = (char)(pc.i + 1 + '0');
			else if (src != '.' && dst != '.')
			{
				tbl[pos] = 'x' /*dest overwrite*/;
#ifdef DBGMSG
				cout << "overwritten" << endl;
#endif
				return false;
			}
		}
	}
#ifdef DBGMSG
	cout << "success" << endl;
#endif
	return true;
}
void printTable(char* table)
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cout << table[l * i + j];
		}
		cout << endl;
	}
}
int findOptimalInterception(char* tbl, piece pc, deque<pair<coord, char*>>* avail_q)
{
	int count = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
		{
#ifdef DBGMSG
			cout << "--- begin - ";
#endif
			char* intercept = new char[l * l];
			memcpy(intercept, tbl, l * l * sizeof(char));
			if (tryIntercept(intercept, pc, j, i))
			{
				coord cd = { j,i };
				avail_q->push_back(make_pair(cd, intercept));
				count++;
			}
#ifdef DBGMSG
			print_Table(intercept);
			cout << "--- end" << endl;
#endif
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

	sort(pcs, pcs + 5, pieceComparator);

	char* tbl = new char[l * l]{ 0 };
	for (int i = 0; i < l * l; i++) tbl[i] = '.'; // replacement of strset

	deque<pair<coord, char*>> q;
	vector<char*> designs;
	findOptimalInterception(tbl, pcs[0], &q);
	int pcord = 1;
	while (!q.empty())
	{
		// copy all to q2
		deque<pair<coord, char*>> q2;
		while (!q.empty())
		{
			q2.push_back(q.front());
			q.pop_front();
		}

		// read all from q2 write all to q
		while (!q2.empty())
		{
			if (pcord == 5)
			{
				printTable( max_element(q2.begin(), q2.end(), tableComparator)->second);
				return 0;
			}
			else
			{
				pair<coord, char*> top = q2.front();
				q2.pop_front();
				findOptimalInterception(top.second, pcs[pcord], &q);
			}
		}
		pcord++;
	}

	cout << "gg" << endl;
}
