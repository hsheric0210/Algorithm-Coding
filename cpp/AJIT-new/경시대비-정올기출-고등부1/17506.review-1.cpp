/*
쇼핑몰-정올2019
https://43.200.211.173/contest/17/problem/17506
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct _A { int idx, idi, wi; } A;
typedef unsigned long long ULL;
int i, j, k, l, n, w;
ULL total=0;
A t1, t2;

// 구현 실수 I: wi끼리 비교하는 부등호 방향이 잘못되었다. '<'가 아니라 '>'이어야 한다.
//auto cmp1 = [](A a, A b) {return a.wi < b.wi || a.wi == b.wi && a.idx < b.idx; };
//auto cmp2 = [](A a, A b) {return a.wi < b.wi || a.wi == b.wi && a.idx > b.idx; };

auto cmp1 = [](A a, A b) {return a.wi > b.wi || a.wi == b.wi && a.idx > b.idx; };

// 구현 실수 II: cmp2의 두 부등호의 방향이 모두 잘못되었다.
// 참고: wi끼리 비교하는 부등호는 cmp1, cmp2 둘 사이에 차이가 없지만, idx를 비교하는 부등호가 서로 다르다는 점을 기억하도록 한다.
//auto cmp2 = [](A a, A b) {return a.wi > b.wi || a.wi == b.wi && a.idx < b.idx; };
auto cmp2 = [](A a, A b) {return a.wi < b.wi || a.wi == b.wi && a.idx > b.idx; };

priority_queue<A, vector<A>, decltype(cmp1)>q1(cmp1);
vector<A>q2;
queue<A>waiting;
int main()
{
	cin >> n >> k;
	for (l = 0; l < n; l++)
	{
		cin >> i >> w;
		if (l < k)
			q1.push({ l+1, i, w }); // if there're any available cashers
		else
			waiting.push({ 0, i, w }); // not enough cashers
	}
	while (!q1.empty())
	{
		t1 = q1.top();
		q1.pop();
		q2.push_back(t1);
		if (!waiting.empty())
		{
			t2 = waiting.front();
			waiting.pop();
			q1.push({ t1.idx, t2.idi, /*IMPORTANT ->*/t2.wi + t1.wi/*<- IMPORTANT*/}); // push waiting customer to empty casher
		}
	}
	sort(q2.begin(), q2.end(), cmp2);
	for (i = 0, w = q2.size(); i < w; i++)
		total += (ULL)q2[i].idi * (i + 1);
	cout << total << endl;
}