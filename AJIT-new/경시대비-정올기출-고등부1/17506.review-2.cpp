/*
쇼핑몰-정올2019
https://43.200.211.173/contest/17/problem/17506
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef unsigned long long ULL;
typedef struct _A { int idx, idi, wi; } A;
int i, j=1, k, l, n, w;
auto cmp1 = [](A a, A b) {return a.wi > b.wi || a.wi == b.wi && a.idx > b.idx; }; // 들어갈 때
auto cmp2 = [](A a, A b) {return a.wi < b.wi || a.wi == b.wi && a.idx > b.idx; }; // 나갈 때 -- 첫번째로 구현할 당시, 나갈 때의 힙을 딱히 만들지 않고, 한 개의 힙만으로 구현하려다가 어려움 겪었었다
priority_queue<A, vector<A>, decltype(cmp1)>q1(cmp1);
priority_queue<A, vector<A>, decltype(cmp2)>q2(cmp2);
queue<A>waitlist;
vector<A>ans;
A p, q;
ULL total;
int main()
{
	cin >> n >> k;
	for (l = 0; l < n; l++)
	{
		cin >> i >> w;
		if (l < k)
			q1.push({ l, i,w });
		else
			waitlist.push({ 0,i,w });
	}
	while (!q1.empty())
	{
		p = q1.top();
		q1.pop();
		q2.push(p);
		if (!waitlist.empty())
		{
			q = waitlist.front();
			waitlist.pop();
			q1.push({ p.idx, q.idi, p.wi + q.wi });
		}
	}
	while (!q2.empty())
	{
		ans.push_back(q2.top());
		q2.pop();
	}
	for (i = 0, j = /*q2 // wtf? */ ans.size(); i < j; i++)
		total += (ULL)ans[j - i - 1].idi * (i + 1);
	cout << total << endl;
}
