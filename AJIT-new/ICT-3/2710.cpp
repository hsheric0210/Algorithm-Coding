// �ݶ� ����
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
		B[i - 1], // 1. �̹� �� �� ���ñ�
		A[i] + B[i - 2], // 2. �̹� ��, �������� ������ ���ñ�
		A[i] + A[i - 1] + B[i - 3] }); // 3. �̹� �Ͱ� ���� ��, ������������ ������ ���ñ�
	cout << B[n - 1];
	return 0;
}