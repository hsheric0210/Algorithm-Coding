// 콜라 시음
#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, n, A[10005], B[10005];
int main()
{
	cin >> n;
	for (i = 0; i < n; i++) cin >> A[i];
	B[0] = A[0]; B[1] = A[0] + A[1]; B[2] = max(A[0] + A[2], A[1] + A[2]);
	for (i = 3; i < n; i++) B[i] = max({
		B[i - 1], // 1. 이번 것 안 마시기
		A[i] + B[i - 2], // 2. 이번 것, 이전이전 최적값 마시기
		A[i] + A[i - 1] + B[i - 3] }); // 3. 이번 것과 이전 것, 이전이전이전 최적값 마시기
	cout << B[n - 1];
	return 0;
}