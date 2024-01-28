/*
문제명: 갱스터
교실: 고급-2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int N, K, T, i, j, k, l, m, n, o, p, q, r, Ti[105], Pi[105], Si[105], D1[30005][105], D2[30005][105];
void push(int i, int j)
{
	if (i <= 0 || j < 0 || i > T || j > K || j > i) return; // bound check
	int v2 = D1[i][j];
	int v3 = max({ D2[i][j], v2 + D2[i - 1][j], v2 + D2[i - 1][j + 1]});
	if (j > 0 && j - 1 <= i) // negative indexing prevention
		v3 = max(v3, v2 + D2[i - 1][j - 1]);
	D2[i][j] = v3;
}
int main()
{
	cin >> N >> K >> T;
	for (i = 0; i < N; i++) cin >> Ti[i];
	for (i = 0; i < N; i++) cin >> Pi[i];
	for (i = 0; i < N; i++) cin >> Si[i]; // > 0
	for (i = 0; i < N; i++) D1[Ti[i]][Si[i]] = Pi[i];
	for (i = 0; i <= T; i++) for (j = 0; j <= min(i + 1, K); j++) push(i, j);
#ifndef ONLINE_JUDGE
	cout << "D1\n";
	for (i = 0; i <= T; i++)
	{
		cout << setw(2) << i << ": ";
		for (j = 0; j <= K; j++)
		{
			cout << setw(3) << D1[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "D2\n";
	for (i = 0; i <= T; i++)
	{
		cout << setw(2) << i << ": ";
		for (j = 0; j <= K; j++)
		{
			cout << setw(3) << D2[i][j] << ' ';
		}
		cout << '\n';
	}
#endif

	cout << *max_element(D2[T], D2[T] + N + 1);
	return 0;
}