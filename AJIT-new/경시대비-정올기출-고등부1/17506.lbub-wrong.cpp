/*
쇼핑몰-정올2019
https://43.200.211.173/contest/17/problem/17506
*/
#include<iostream>
#include<algorithm>
#include<deque>
#include<queue>
using namespace std;
typedef struct _A { int i, w; } A;
deque<A> tc(100000, { 0,0 }); // check if this will cause memory overflow // 테스트 케이스: i=고객번호, w=계산물품갯수
A arr[100000]; // i=계산대번호, w=남은 계산 시간
bool acmp(A a, A b) { return a.w < b.w; }
int i, j, k, l, n, m, w;
unsigned long long incr = 1, total = 0;
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); //speed trick
	cin >> n >> k; // n=nTestCase, k=nCarts
	for (l = 0; l < n; l++)
	{
		cin >> i >> w;
		tc.push_back({ i, w });
	}

	A empty = { 0,0 };
	while (1) // main loop
	{
		int modified = 0;

		if (!tc.empty())
		{
			// push
			auto push = lower_bound(arr, arr + 100000, empty, acmp);
			cout << "found and inserted to empty pos: " << distance(arr, push) << endl;
			while (push != arr + 100000 && !tc.empty()) // if avail
			{
				*push = tc.front(); // we can optimize this from deque front call to array + index call
				tc.pop_front();
				modified = 1;
				push = lower_bound(arr, arr + 100000, empty, acmp);
			}
		}

		// tick
		for (i = 0; i < 100000; i++) // it has to be optimized, but it can't be.
			if (arr[i].w > 0)
			{
				cout << "decr" << endl;
				arr[i].w--;
				modified = 1;
			}

		// pop
		auto pop = upper_bound(arr, arr + 100000, empty, acmp);
		while (pop != arr + 100000) // if avail
		{
			int ad = pop->i * incr++;
			cout << "Add:" << ad << endl;
			total += ad;
			modified = 1;
			pop = upper_bound(arr, arr + 100000, empty, acmp);
		}

		if (!modified) break;
	}
	cout << total << endl;
}