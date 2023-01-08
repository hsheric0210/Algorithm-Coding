/*
기차 교차로
https://43.200.211.173/contest/17/problem/827
뇌 빼놓고 풀었는데 풀림 ㅋㅋ; (디버깅 1번도 안하고 테스트도 안해보고 그대로 제출했는데 OK뜸)
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> r;
deque<int> c;
deque<int> m;
deque<char> act;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int d; cin >> d;
		r.push_back(d);
	}

	while (true)
	{
		if (!r.empty())
		{
			int _r = r.front();
			r.pop_front();
			c.push_front(_r);
			act.push_back('S');
		}

		while (!c.empty() && (m.empty() ? c.front() == 1 : c.front() == m.back() + 1))
		{
			m.push_back(c.front());
			c.pop_front();
			act.push_back('X');
		}

		if (r.empty())
		{
			if (!c.empty() || m.size() < n)
			{
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			else
				break;
		}
	}
	for (auto i = act.begin(); i != act.end(); i++)
		cout << *i;
	cout << endl;
}