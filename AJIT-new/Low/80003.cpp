/*
�ﰢ�� �����
https://43.200.211.173/contest/17/problem/80003
https://blockdmask.tistory.com/196
*/
#include <iostream>
using namespace std;
int n, a, b, c, d = 0;
int main()
{
	cin >> n;
	if (!(n < 3 || n == 4))
		for (a = 1; a <= n / 3; a++) // a: 1..(n/3)
		{
			for (b = a; b <= n / 2; b++) // b: a..(n/2)
			{
				c = n - a - b;
				if (c < b)
					break; // �յ��� 3������ �ﰢ�� �߿���, C�� ���� ū �ϳ��� ��츸 ����
				if (a + b > c) // �ﰢ���� ���������� �����ϴ��� �˻�
					d++;
			}
		}
	cout << d << endl;
	return 0;
}