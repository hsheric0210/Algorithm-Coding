/*
문제명: 가로수
알고리즘: GCD, 유클리드 호제법
*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int N, i, j, k, l, m, n, o, p, q, r, P[100005];
set<int>V;
int gcd(int a, int b) { int i, j = max(a, b), k = min(a, b);  while (1) { i = j % k;   if (i == 0)    return k;   j = k;   k = i; }  return 1; }
int main()
{
	cin >> N; for (i = 0; i < N; i++) { cin >> P[i]; V.insert(P[i]); }
	if (N <= 2) { cout << 0; return 0; } // Edge case: 2
	sort(P, P + N);
	k = P[1] - P[0]; for (i = 1; i < N - 1; i++) k = gcd(k, P[i + 1] - P[i]); // https://www.acmicpc.net/board/view/122475 수정
	auto m = minmax_element(P, P + N);
	cout << max(0, (*(m.second) - *(m.first)) / k + 1 - N);
	return 0;
}