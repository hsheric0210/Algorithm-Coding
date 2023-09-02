/*
문제명: 기차 교차로
교실: 고급-1
난이도: Mid
알고리즘: 스택
*/
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>
#include <string>
using namespace std;

int N, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
deque<int>V,S;
vector<char>O;
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> j;
		V.push_back(j);
	}

	p = 1;
	while (1)
	{
		if (!S.empty() && S.back() == p)
		{
			O.push_back('X');
			S.pop_back();
			p++;
		}
		else if (!V.empty())
		{
			O.push_back('S');
			S.push_back(V.front());
			V.pop_front();
		}
		else break;
	}

	if (!S.empty()) cout << "IMPOSSIBLE";
	else cout << string(O.begin(), O.end());
	return 0;
}