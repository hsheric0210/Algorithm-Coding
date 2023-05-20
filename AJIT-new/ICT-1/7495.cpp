// ICT-1 : 분수찾기
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i, j, k, l, p, q, r, m, n, x, y, z;
#define ISZ 10005
int A[ISZ], B[ISZ];
int main()
{
	A[0] = B[0] = 1;
	p = 4, q = 2;
	for (i = 0; i < ISZ-5; i++)
	{
		A[i + 1] = A[i] + (i % 2 ? p : 1);
		if (i % 2)
			p += 4;

		B[i + 1] = B[i] + (i % 2 ? 1 : q);
		if (!(i % 2))
			q += 4;
	}

	cin >> n;
	x = lower_bound(A, A + ISZ, n) - A;
	y = lower_bound(B, B + ISZ, n) - B;
	x = x - (A[x] != n);
	y = y - (B[y] != n);
	p = A[x]>B[y];
	q = p ? x : y;
	r = p ? A[x] : B[y];
	if (p) // 좌하단으로 내려가기
	{
		n -= r;
		x = 1 + n;
		y = q + 1 - n;
	}
	else // 우상단으로 올라가기
	{
		n -= r;
		x = q + 1 - n;
		y = 1 + n;
	}
	cout << x << '/' << y << '\n';
	return 0;
}