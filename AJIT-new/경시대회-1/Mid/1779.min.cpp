/*
종이자르기
https://43.200.211.173/contest/17/problem/1779
C-Minifier-friendly version
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;
typedef struct _xy { int x; int y; } xy;
typedef struct _pc {
	int i; int v; xy bb;
	char* d;
} pc;
int l;
bool it(char* t, pc p, int x, int y) // isIntercepts
{
	for (int i = 0; i < p.bb.y; i++)
	{
		for (int j = 0; j < p.bb.x; j++)
		{
			if (x + j < 0 || x + j >= l || y + i < 0 || y + i >= l) return false; // Index error
			char s = p.d[i * p.bb.x + j];
			int p2 = (i + y) * l + j + x;
			if (s == '#' && t[p2] == '.') t[p2] = (char)(p.i + 1 + '0');
			else if (s != '.' && t[p2] != '.') return false; // Overwritten
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
int fint(char* t, pc p, deque<pair<xy, char*>>* q) // findInterception
{
	int c = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
		{
			char* tc = new char[l * l];
			memcpy(tc, t, l * l * sizeof(char));
			if (it(tc, p, j, i))
			{
				xy cd = { j,i };
				q->push_back(make_pair(cd, tc));
				c++;
			}
		}
	return c;
}
int pcm(pc a, pc b) { return a.v == b.v ? a.i > b.i : a.v > b.v; }
bool tcm(pair<xy, char*> a, pair<xy, char*> b) { return memcmp(a.second, b.second, l * l * sizeof(char)) > 0; }
int main()
{
	cin >> l;
	pc* ps = new pc[5];
	for (int i = 0; i < 5; i++)
	{
		int n, m; cin >> n >> m;
		char* c = new char[n * m]{ 0 };
		int v = 0;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				char ch; cin >> ch;
				if (ch == '#')
					v++;
				c[m * j + k] = ch;
			}
		xy b = { m, n };
		pc p = { i, v, b, c };
		ps[i] = p;
	}
	sort(ps, ps + 5, pcm);
	char* t = new char[l * l]{ 0 };
	for (int i = 0; i < l * l; i++) t[i] = '.';
	deque<pair<xy, char*>> q;
	fint(t, ps[0], &q);
	int pi = 1;
	while (!q.empty())
	{
		deque<pair<xy, char*>> qc;
		while (!q.empty())
		{
			qc.push_back(q.front());
			q.pop_front();
		}

		while (!qc.empty())
		{
			if (pi == 5)
			{
				pt(max_element(qc.begin(), qc.end(), tcm)->second);
				return 0;
			}
			else
			{
				pair<xy, char*> top = qc.front();
				qc.pop_front();
				fint(top.second, ps[pi], &q);
			}
		}
		pi++;
	}
	cout << "gg" << endl;
}
