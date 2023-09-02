/*
문제명: 괄호의 값
교실: 고급-1
난이도: Mid
알고리즘: 재귀, Nested bracket counting
*/
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>
#include <string>
using namespace std;

int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, ERR;
string S;
int recurse(string s)
{
	if (s == "()") return 2;
	if (s == "[]") return 3;

	vector<string>nested;
	string tmp;
	tmp.reserve(s.length()); // optimize memory allocations
	for (int i = 0, j = s.length(); i < j; i++)
	{
		if (s[i] == '(') p++;
		if (s[i] == ')') p--;
		if (s[i] == '[') q++;
		if (s[i] == ']') q--;
		tmp += s[i];
		if (p == 0 && q == 0)
		{
			nested.push_back(tmp);
			tmp.clear();
		}
	}
	if (p != 0 || q != 0)
	{
		ERR = 1; // nesting mismatch
		//cout << "nesting error\n";
		return 0;
	}

	if (nested.size() == 1)
	{
		// single-nest
		if (s[0] == '(') return recurse(s.substr(1, s.length() - 2)) * 2;
		if (s[0] == '[') return recurse(s.substr(1, s.length() - 2)) * 3;
	}

	// multi-nest
	int l = 0;
	for (string n : nested)
		l += recurse(n);
	return l;
}
int main()
{
	cin >> S;
	v = recurse(S);
	if (ERR) cout << 0;
	else cout << v;
	return 0;
}