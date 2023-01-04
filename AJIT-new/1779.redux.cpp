/*
종이자르기
https://43.200.211.173/contest/17/problem/1779
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;
typedef struct _pos { int x; int y; } pos;
typedef struct _pc {
	int i; int vol; pos bb;
	char* d;
} pc;
int l;
bool intr(char* t, pc pc, int ox, int oy) // isIntercepts
{
	for (int i = 0; i < pc.bb.y; i++)
	{
		for (int j = 0; j < pc.bb.x; j++)
		{
			if (ox + j < 0 || ox + j >= l || oy + i < 0 || oy + i >= l) return false; // Index error
			char src = pc.d[i * pc.bb.x + j];
			int pos = (i + oy) * l + j + ox;
			if (src == '#' && t[pos] == '.') t[pos] = (char)(pc.i + 1 + '0');
			else if (src != '.' && t[pos] != '.') return false; // Overwritten
		}
	}
	return true;
}
void pt(char* t) // printTable
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
			cout << t[l * i + j];
		cout << endl;
	}
}
int fint(char* table, pc pc, deque<pair<pos, char*>>* workQueue) // findInterception
{
	int count = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
		{
			char* tcpy = new char[l * l];
			memcpy(tcpy, table, l * l * sizeof(char));
			if (intr(tcpy, pc, j, i))
			{
				pos cd = { j,i };
				workQueue->push_back(make_pair(cd, tcpy));
				count++;
			}
		}
	return count;
}
int pcmp(pc a, pc b) { return a.vol == b.vol ? a.i > b.i : a.vol > b.vol; }
bool tcmp(pair<pos, char*> a, pair<pos, char*> b) { return memcmp(a.second, b.second, l * l * sizeof(char)) > 0; }
int main()
{
	cin >> l;
	pc* pcs = new pc[5];

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
		pos bound = { m, n };
		pc pc = { i, vol, bound, c };
		pcs[i] = pc;
	}

	// Sort pieces by volume and id
	sort(pcs, pcs + 5, pcmp);

	// Prepare initial table
	char* t = new char[l * l]{ 0 };
	for (int i = 0; i < l * l; i++) t[i] = '.'; // replacement of strset

	deque<pair<pos, char*>> q;
	fint(t, pcs[0], &q);
	int pcidx = 1;
	while (!q.empty())
	{
		// workQueue를 완전히 비운 후 다음에 piece에 대해 작업을 시작하기 위해서는
		// workQueue를 다른 곳으로 복사한 후 처리해야 한다
		deque<pair<pos, char*>> qc;
		while (!q.empty())
		{
			qc.push_back(q.front());
			q.pop_front();
		}

		while (!qc.empty())
		{
			if (pcidx == 5)
			{
				// 5번째 piece까지 모두 처리한 후
				pt(max_element(qc.begin(), qc.end(), tcmp)->second);
				return 0;
			}
			else
			{
				pair<pos, char*> top = qc.front();
				qc.pop_front();
				fint(top.second, pcs[pcidx], &q);
			}
		}
		pcidx++;
	}

	cout << "gg" << endl;
}
