/*
최소 횟수 에디터
https://43.200.211.173/contest/17/problem/80039
*/
#include<iostream>
#include<algorithm>
#include<stack>
#include<tuple>
#include<vector>
using namespace std;
int i, j, k, l, m;
char s1[1005], s2[1005];
vector<char>modbuf;
int ed[1005][1005];
int main()
{
	cin.getline(s1, 1005);
	cin.getline(s2, 1005);
	
	for (i = 1; i < 1005; i++)
		ed[i][0] = ed[0][i] = i;
	for (i = 0; s1[i]; i++)
	{
		modbuf.push_back(s1[i]);
		for (j = 0; s2[j]; j++)
			ed[i + 1][j + 1] = min({ ed[i + 1][j] + 1, ed[i][j + 1] + 1, ed[i][j] + (s1[i] != s2[j]) });
	}
	modbuf.push_back(0);
	cout << ed[i][j] << endl;

	// start backtracking
	stack<pair<int, int>>s;
	s.push(make_pair(i, j));
	while (!s.empty())
	{
		auto top = s.top();
		//s.pop();
		int a = top.first, b = top.second;
		if (a == 0 || b == 0)
			break;
		if (s1[a - 1] == s2[b - 1])
			s.push(make_pair(a - 1, b - 1)); // nothing changes
		else
		{
			initializer_list<tuple<int, int, int, int>> ia = { {ed[a][b - 1], a, b - 1, 1}, {ed[a - 1][b], a - 1, b, 2}, {ed[a - 1][b - 1], a - 1, b - 1, 3} };
			auto xelem = max(ia, [](tuple<int, int, int, int> f, tuple<int, int, int, int> s) {return get<0>(f) < get<0>(s); });
			s.push(make_pair(get<1>(xelem), get<2>(xelem)));
			switch (get<3>(xelem))
			{
			case 1: // insert
				cout << modbuf._Unchecked_begin() << endl;
				modbuf.insert(modbuf.begin() + a, s1[a]);
				break;
			case 2: // remove
				cout << modbuf._Unchecked_begin() << endl;
				modbuf.erase(modbuf.begin() + a);
				break;
			case 3: // substit.
				cout << modbuf._Unchecked_begin() << endl;
				modbuf[a] = s1[a];
				break;
			}
		}
	}
	cout << modbuf._Unchecked_begin() << endl;
}