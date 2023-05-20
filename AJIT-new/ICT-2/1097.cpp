// ICT-2 : 소형 기관차
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<numeric>
using namespace std;
int i, j, k, l, m, n, p, q, r, N, K;
int A[50005], B[50005][4];
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> p;
		A[i + 1] = A[i] + p;
	}
	cin >> K;
	for (i = 1; i <= 3; i++)
	{
		k += K;
		for (j = 0; j+k < N; j++)
			B[j + k][i] = max(B[j+k-1][i], B[j+k-K][i-1] + A[j + k] - A[j + k - K]);

		cout << "B[" << i << "] - ";
		for (int j = 0; j <= N; j++)
			cout << setw(3) << B[j][i] << ' ';
		cout << '\n';
	}
	cout << B[j+k-1][3] << '\n';
}