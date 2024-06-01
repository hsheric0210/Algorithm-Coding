#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, K, N, A[10005];
struct P { int count, divisor; };
vector<P>C;
int main()
{
	cin >> K >> N;
	for (i = 0; i < K; i++)cin >> A[i];
	if (K >= N)
	{
		cout << *max_element(A, A + K);
		return 0;
	}
	for (i = 1;; i++) // 1 ~ 10000 에 대해 모두 일일히 계산해 최적값 찾기
	{
		for (j = 0, k = 0; j < K; j++)
		{
			l = A[j] / i;
			if (k + l < 0) goto skip; // prevent overflow
			k += l;
		}
		C.push_back({ k, i });
		if (k < N) break; // no need to continue more (already reached the limit N)
		continue;

	skip:
		C.push_back({ 0x7fffffff, i });
	}
	P target = { N, 0 };
	auto g = lower_bound(C.rbegin(), C.rend(), target, [](P a, P b) {return a.count < b.count; });
#ifndef ONLINE_JUDGE
	cout << "count=" << g->count << " divisor=" << g->divisor << '\n';
#endif
	cout << g->divisor;
	return 0;
}
