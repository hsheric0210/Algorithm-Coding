#include<iostream>
#include<cmath>
#include<algorithm>
#define L 501
// A = Village array
// B = 2D dp table
// C = 1D dp table
int A[L], B[L][L], C[L];
int i, j, k, l, m, n;
using namespace std;
int main() {
	cin >> n >> m;
	for (i = 1; i <= n; i++) // build 2D dp
	{
		cin >> A[i];
		for (j = 1; j <= i; j++)
		{
			l = (i + j) / 2; // center value
			for (k = j; k <= i; k++)
				B[j][i] += abs(A[k] - A[l]);
			if (j == 1) C[i] = B[j][i];
		}
	}
	// dump 2D dp table
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << B[i][j] << ' ';
		}
		cout << '\n';
	}
	for (k = 2; k <= m; k++) // k=2..m, increm
		for (j = n; j >= k; j--) // j=k..n, decrem
			for (i = j; i >= k; i--) // i=k..j, decrem
				C[j] = min(C[j], C[i - 1] + B[i][j]);
	for (i = 0; i <= n; i++)
		cout << C[i] << ' ';
	cout << '\n';
	cout << C[n];
	return 0;
}