/*
소들의 시위
https://43.200.211.173/contest/17/problem/80022
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef struct _cow
{
	int i; int ai;
} cow;
bool cm(cow a, cow b) { return a.ai > b.ai; }
int main()
{
	int n; cin >> n;
	deque<cow> q;
	for (int i = 0; i < n; i++)
	{
		int ai;  cin >> ai;
		cow c = { i, ai };
		q.push_back(c);
	}
	sort(q.begin(), q.end(), cm);
	
}