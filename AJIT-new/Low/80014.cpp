/*
car racing
https://43.200.211.173/contest/17/problem/80014
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	int n; cin >> n;
	deque<int> in, line, bypass;
	for (int i = 0; i < n; i++)
	{
		int d; cin >> d; in.push_back(d);
	}
	while (!in.empty() || !bypass.empty())
	{
		int targetNumber = line.empty() ? 1 : line.back() + 1;
		if (!bypass.empty())
		{
			int btop = bypass.front();
			if (btop == targetNumber)
			{
				bypass.pop_front();
				line.push_back(btop);
				continue; // succeed to push
			}
			else if (in.empty())
			{
				break; // failed
			}
		}
		if (!in.empty())
		{
			int itop = in.front();
			in.pop_front();
			if (itop == targetNumber)
				line.push_back(itop);
			else
				bypass.push_back(itop);
		}
	}
	if (line.size() == n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}