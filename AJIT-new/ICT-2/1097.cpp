// ICT-2 : 소형 기관차
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<numeric>
using namespace std;
int i, j, k, l, m, n, p, q, r, N, K;
int S[50005], DP[50005][4];
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> p;
		S[i + 1] = S[i] + p; // "누적합"
	}
	cin >> K;
	for (i = 1; i <= 3; i++)
	{
		k += K;
		for (j = 0; j+k <= N; j++)
			DP[j + k][i] = max(DP[j+k-1][i], DP[j+k-K][i-1] + S[j + k] - S[j + k - K]);

		// 어떻게 작동하는지는 아래 덤프문 활성화시키면 쉽게 알 수 있을 것이다
		//#define DUMP

		// DEBUG
#ifdef DUMP
		cout << "B[" << i << "] - ";
		for (int j = 0; j <= N; j++)
			cout << setw(3) << DP[j][i] << ' ';
		cout << '\n';
#endif
		// DEBUG
	}
	cout << DP[j+k-1][3] << '\n';
}