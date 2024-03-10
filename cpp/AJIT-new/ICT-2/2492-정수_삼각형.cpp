// ICT-2 : 정수 삼각형
// 아랫쪽 두 수 중 최댓값의 누적합 -> 삼각형 꼭대기에 있는 수가 정답
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, p, q, r, x, y, z;
int A[505][505];
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			cin >> A[i][j];

	for(i=n-1; i>0; i--)
		for (j = 0; j <= i; j++)
			A[i - 1][j] = A[i - 1][j] + max(A[i][j], A[i][j + 1]); // 삼각형 아랫쪽부터 MAX 누적합 -> 삼각형 꼭대기에 있는 수가 정답

//#define DUMP
#ifdef DUMP
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
#endif
	cout << A[0][0] << '\n';
	return 0;
}