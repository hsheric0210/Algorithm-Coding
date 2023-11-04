/*
문제명: 예산
교실: 고급-1
난이도: Mid
알고리즘: 파라메트릭 서치(이진 탐색)
*/
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>
#include <string>
using namespace std;

int N, M, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
int V[10005];
int calc(int limit)
{
	for (i = 0, k=0; i < N; i++)
		k += min(V[i], limit);
	return k;
}
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> V[i];
		k += V[i];
		l = max(l, V[i]);
	}
	cin >> M;

	if (k <= M) // 배정 가능
	{
		cout << l;
		return 0;
	}

	// parametric search (binary search)
	x = 0;
	y = l;
	while (1)
	{
		p = (x + y) / 2;
		q = calc(p);
		//cout << "x=" << x << " y=" << y << " p=" << p << " total=" << q << '\n';
		if (x > y) break;
		if (q <= M)
			x = p + 1;
		else
			y = p - 1;
	}

	cout << p;
	return 0;
}