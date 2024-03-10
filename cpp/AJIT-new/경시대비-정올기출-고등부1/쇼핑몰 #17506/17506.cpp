/*
쇼핑몰-정올2019
https://43.200.211.173/contest/17/problem/17506
소요시간: 약 3시간 반
*/
#include<iostream>
#include<algorithm>
#include<deque>
#include<queue>
#define DBGPRINT
using namespace std;
typedef struct _A { int index, idi, wi; } A;
auto cmp = [](A a, A b) { return a.wi > b.wi || a.wi == b.wi && a.index > b.index; }; // 구현 실수 I: 첫 번째 우선순위 큐 비교자에서는 상품 갯수가 같다면 인덱스가 클수록 내림차순이어야 했으나, 오름차순으로 구현하는 바람에 한참 시간을 보냈다
int i, j = 1, k, l, n, m, w;
unsigned long long total = 0;
deque<A> awaiting;
priority_queue<A, vector<A>, decltype(cmp)>pq(cmp);
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); //speed trick
	cin >> n >> k; // n=nTestCase, k=nCarts

	for (l = 0; l < n; l++)
	{
		cin >> i >> w;
		if (l < k) // 모든 계산대 꽉꽉 채우기
			pq.push({ l + 1, i, w });
		else
			awaiting.push_back({ 0, i, w }); // 대기 목록에 추가
	}

	vector<A>tq;
	vector<A>tmp;
	while (!pq.empty())
	{
		auto top = pq.top(); // 가장 시간이 적게 걸리는 고객들 중 가장 index가 큰 고객 pop
		pq.pop();
		tq.push_back(top);
		//total += (unsigned long long)top.idi * (j++);
#ifdef DBGPRINT
		cout << "[POP] " << top.idi << endl;
#endif // DBGPRINT
		vector<A> q;
		if (!awaiting.empty())
		{
			// 비워진 자리에 대기열 맨 앞의 고객 push
			A fr = awaiting.front();
			awaiting.pop_front();
			A nu = { top.index, fr.idi, fr.wi + top.wi }; // SOL: pq에서 pop한 고객의 시간 만큼 pq에 있던 다른 고객들에게도 시간이 흘렀을 것이다. 그러나 pq에 대하여 foreach를 돌려 시간을 마이너스하는 것이 불가능하므로, 생각을 거꾸로 해서 새로 추가하는 고객의 시간에 플러스를 하는 것이다.
#ifdef DBGPRINT
			cout << "[PUSH] " << fr.idi << " " << fr.wi + top.wi << endl;
#endif // DBGPRINT
			pq.push(nu);
		}
#ifdef DBGPRINT
		vector<A>tmp;
		while (!pq.empty())
		{
			tmp.push_back(pq.top());
			pq.pop();
		}
		sort(tmp.begin(), tmp.end(), [](A a, A b) {return a.index < b.index; });
		for (auto a = tmp.begin(); a != tmp.end(); a++)
			cout << "[" << a->index << "]=(" << a->idi << " " << a->wi << ")" << endl;
		cout << endl;
		while (!tmp.empty())
		{
			pq.push(tmp.back());
			tmp.pop_back();
		}
#endif // DBGPRINT
	}

	// 생각의 실수: 전체 값들에 대하여 곧바로 total에 add를 하는 것이 아니라 한번 다시 time과 index에 대하여 정렬을 시켜서 진짜로 해당 손님 처리 시간이 해당 값이 맞는지, 시간이 같다면 (문제에서 주어진 조건대로) 인덱스가 더 큰 손님을 우선하여 처리하기 위하여 반드시 정렬이 필요하다.
	sort(tq.begin(), tq.end(), [](A a, A b) {return a.wi < b.wi || a.wi == b.wi && a.index > b.index; });
	for (i = 0; i < tq.size(); i++)
	{
#ifdef DBGPRINT
		cout << "[SORTED] " << tq[i].index << " " << tq[i].idi << " " << tq[i].wi << endl;
#endif // DBGPRINT
		total += (unsigned long long)tq[i].idi * (i + 1);
	}
	cout << total << endl;
}