// Olympiad > �ѱ������ø��ǾƵ� > KOI 1997 > �ߵ�� 1��
#define _CRT_SECURE_NO_WARNINGS // ���� VCRT
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int i, j, k, l, x, y, z, N;
char s[105];
int cmp(int i, int j, int len) { return (i < 0 || j < 0) ? -2 : strncmp(s + i, s + j, len); }
int bad(int i)
{
	for (x = 1; x <= i + 1; x++)
		if (!cmp(i - x + 1, i - x * 2 + 1, x)) // ���� X¥�� �κм��� �˻�
			return true;
	return false;
}
int main()
{
	cin >> N;//���Ǥ������ä�������������!
	// �ϳ��ϳ� �ٿ������� �κм��� �˻�
	s[0] = '1';
	for (i = 1; i < N; i++)
	{
	retry:
		for (j = 1; j <= 3; j++)
		{
			s[i] = j + '0';
			if (!bad(i))
				goto ok;
		}
		cout << "all-three fail @ i=" << i << '\n';
		// all three failed the test -> ��Ʈ��ŷ�ϸ� ���� ���� �� 3�� �ƴ� ù ��° ���� 1 ������Ű�� �ٽ� �õ�
		for (z = 1;; z++)
		{
			if (s[i - z] < '3')
			{
				s[i - z]++;
				break;
			}
		}
		goto retry
			;

	ok:;
	}
	cout << s << '\n';
}