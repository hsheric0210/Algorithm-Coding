// ¤�Ź���
#include<iostream>
using namespace std;
int i, j, k, l, a, b, d, N, A[1000005];
int main()
{
	cin >> a >> b >> d >> N;
	for (i = 0; i < a; i++) A[i] = 1;
	for (i = a; i <= N; i++) A[i] = (A[i - 1] // ���� �� ���� ������
		+ A[i - a] //(���� �Ұ��� ���� ���� �������� ��)���� ���� �¾ ������
		- (i-b>=0 ?A[i - b]:0) + 1000/*mod compensation*/) % 1000; //���� ���� �Ұ����� ������
	if (N < d)
		cout << A[N];
	else
		cout << (A[N] - A[N - d] + 1000) % 1000;
	cout << '\n';
	//for (i = 0; i <= N; i++)
	//	cout << A[i] << ' ';
	//cout << '\n';
	return 0;
}