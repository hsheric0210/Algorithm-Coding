/*
A Game
https://43.200.211.173/contest/17/problem/80021
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	int n; cin >> n;
	deque<int> q;
	for (int i = 0; i < n; i++)
	{
		int k; cin >> k;
		q.push_back(k);
	}

	int a = 0, b = 0, t = 0;
	while (!q.empty())
	{
		int take; // 0=front 1=back
		if (q.size() > 4 && q.front() == q.back()) // 어차피 어느 쪽을 선택해도 내가 얻는 점수가 크다면, 최대한 다음 턴에 상대방에게 점수를 안 주는 쪽으로
		{
			int fbak = q.front();
			int bbak = q.back();
			q.pop_front();
			q.pop_back();
			take = q.front() > q.back();
			q.push_front(fbak);
			q.push_back(bbak);
		}
		else
			take = q.front() < q.back();
		int score = take ? q.back() : q.front();
		if (take) q.pop_back(); else q.pop_front();
		if (!t)
			a += score;
		else
			b += score;
		t = !t;
	}
	cout << a << "  " << b << endl;
}