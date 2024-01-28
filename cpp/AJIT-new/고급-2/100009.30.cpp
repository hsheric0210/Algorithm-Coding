/*
문제명: 갱스터
교실: 고급-2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, T, i, j, k, l, m, n, o, p, q, r, Ti[105], Pi[105], Si[105], D1[30005][105], D2[30005][105];
void push(int i, int j, int v)
{
	if (i < 0 || j < 0 || i > T || j > K) return; // bound check
	D2[i][j] = max(D2[i][j], D1[i][j] + v);
}
//#define BACK_TO_FRONT_IMPL // 뒤에서 앞으로 보는 구현 사용
int main()
{
	cin >> N >> K >> T;
	for (i = 0; i < N; i++) cin >> Ti[i];
	for (i = 0; i < N; i++) cin >> Pi[i];
	for (i = 0; i < N; i++) cin >> Si[i];

	for (i = 0; i < N; i++) D1[Ti[i]][Si[i]] = Pi[i];

#if defined BACK_TO_FRONT_IMPL
	for (i = T; i > 0; i--)
#else
	for (i = 0; i < T; i++)
#endif
	{
		for (j = 0; j <= min(i, K); j++)
		{
#ifdef BACK_TO_FRONT_IMPL
			push(i - 1, j - 1, D2[i][j]);
			push(i - 1, j, D2[i][j]);
			push(i - 1, j + 1, D2[i][j]);
#else
			push(i + 1, j - 1, D2[i][j]);
			push(i + 1, j, D2[i][j]);
			push(i + 1, j + 1, D2[i][j]);
#endif
		}
	}
#ifndef ONLINE_JUDGE
	cout << "D1\n";
	for (i = 0; i < T; i++)
	{
		for (j = 0; j <= K; j++)
		{
			cout << D1[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "D2\n";
	for (i = 0; i < T; i++)
	{
		for (j = 0; j <= K; j++)
		{
			cout << D2[i][j] << ' ';
		}
		cout << '\n';
	}
#endif

#ifdef BACK_TO_FRONT_IMPL
	cout << D2[0][0];
#else
	cout << *max_element(D2[T], D2[T] + N + 1);
#endif
	return 0;
}