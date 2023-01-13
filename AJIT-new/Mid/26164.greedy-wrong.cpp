/*
돼지 저금통
https://43.200.211.173/contest/17/problem/26164
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef struct _testcase
{
	int p;
	int w;
} testcase;
bool tccmp(testcase c1, testcase c2) { return c1.w > c2.w; }
int main()
{
	int e, f, n; cin >> e >> f >> n;
	
	deque<testcase> q;
	for (int i = 0; i < n; i++)
	{
		// parse test cases
		int p, w;
		cin >> p >> w;
		testcase tc = { p,w };
		q.push_back(tc);
	}
	sort(q.begin(), q.end(), tccmp);

	int tw = f - e; // total weight
	int tp = 0;
	/*greedy*/
	while (!q.empty())
	{
		testcase top = q.front();
		if (tw >= top.w)
		{
			tp += top.p;
			tw -= top.w;
		}
		else
			q.pop_front();
	}
	if (tw != 0)
	{
		tp = -1;
	}
	cout << tp << endl;
	return 0;
}