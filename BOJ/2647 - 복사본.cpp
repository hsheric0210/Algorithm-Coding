/*
문제명: 검은점과 하얀점 연결
알고리즘: 스택, DP
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
using namespace std;
struct conn { int begin, end, nestlvl; };
int L, i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
vector<pair<int, int>>P;
char ch;
int sum(vector<conn> conns)
{
	int C = 0;
	for (conn c : conns) C += (c.end - c.begin) + c.nestlvl * 2;
	return C;
}
int main()
{
	string s;
	cin >> i >> s;

	// 1. find nestings
	vector<conn>conns;
	deque<pair<int, char>>S;
	for (i = 0, j = s.length(); i < j; i++)
	{
		if (!S.empty() && S.back().second != s[i]) // found pair
		{
			conn pr = { S.back().first, i, S.size() };
			conns.push_back(pr);
			S.pop_back();
			continue;
		}
		S.push_back(make_pair(i, s[i]));
	}

	// 2. tree-ize
	//for ()

	// 2. try merging two adjacent pair of connection
	// '┌──┐┌──┐' to '┌─────┐'
	//  │ A  ││  B │      │ A ┌┐ B │ 
	sort(conns.begin(), conns.end(), [](conn a, conn b) { return a.nestlvl == b.nestlvl ? a.begin < b.begin : a.nestlvl < b.nestlvl; });
	for (i = 0, j = conns.size() - 1; i < j; i++)
	{
		vector<conn> new_conns;
		if (conns[i].nestlvl != conns[i + 1].nestlvl) continue; // must have same nesting level
		if (conns[i].end + 1 < conns[i + 1].begin) continue; // must adjacent

		// copy other connections
		for (k = 0; k < i; k++)
			new_conns.push_back(conns[k]);
		for (k = i + 2; k < conns.size(); k++)
			new_conns.push_back(conns[k]);

		// try merge conns[i] and conns[i+1]
		new_conns.push_back({ conns[i].begin, conns[i + 1].end, conns[i].nestlvl + 1 }); // outer
		new_conns.push_back({ conns[i].end, conns[i].begin, 1 }); // inner (nesting level is always 1)
		
		x = sum(conns);
		y = sum(new_conns);
		if (x > y) // compare
		{
			cout << "Merging connection " << i << '(' << conns[i].begin+1 << " - " << conns[i].end + 1 << ") and " << i + 1 << '(' << conns[i+1].begin + 1 << " - " << conns[i+1].end + 1 << ") is better(" << x << " > " << y << ")\n";
			conns = new_conns; // and exchange
			sort(conns.begin(), conns.end(), [](conn a, conn b) { return a.nestlvl == b.nestlvl ? a.begin < b.begin : a.nestlvl < b.nestlvl; });
		}
	}

	sort(conns.begin(), conns.end(), [](conn a, conn b) { return a.begin < b.begin; });

	cout << sum(conns) << '\n';
	for (conn c : conns) cout << c.begin+1 << ' ' << c.end+1 << ' ' << v-c.nestlvl+1 << '\n';
	return 0;
}
