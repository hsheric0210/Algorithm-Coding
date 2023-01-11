/*
car racing
https://43.200.211.173/contest/17/problem/80014
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int n, d, b, i, t;
int main()
{
	cin >> n;
	deque<int> iq, oq, bq;
	for (i = 0; i < n; i++)
	{
		cin >> d; iq.push_back(d);
	}
	while (!iq.empty() || !bq.empty())
	{
		t = oq.empty() ? 1 : oq.back() + 1;
		if (!bq.empty())
		{
			b = bq.front();
			if (b == t)
			{
				bq.pop_front();
				oq.push_back(b);
				continue; // succeed to push
			}
			else if (iq.empty())
			{
				break; // failed
			}
		}
		if (!iq.empty())
		{
			i = iq.front();
			iq.pop_front();
			if (i == t)
				oq.push_back(i);
			else
				bq.push_back(i);
		}
	}
	if (oq.size() == n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}