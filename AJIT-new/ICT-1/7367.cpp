// ICT-1 : �Ѽ�
#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
int i, j, k, l, m, n, p, q, r;
ll x, y, z;
#define IMAX 0x7FFFFFFF
bool chk(int n)
{
	if (n <= 99) // �� �ڸ� ���� ���ڴ� �׻� ���������� �̷� �� �ۿ� ����(������ ���Ұ� 2�� �����̸� �� �� ������ �� �� �׻� ���� �Ǳ� ����)
		return true;
	q = -1; // previous digit
	r = IMAX; // previous delta
	for (j = 0, l = log10(n); j <= l; j++)
	{
		p = n / (int)pow(10, j) % 10;
		if (q >= 0) // previous digit avail.
		{
			if (r != IMAX && r != p - q) // delta avail. & changed -> not an arithmetic progression
				return false;
			r = p - q;
		}
		q = p;
	}
	return true;
}
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)if (chk(i))m++;
	cout << m << '\n';
	return 0;
}