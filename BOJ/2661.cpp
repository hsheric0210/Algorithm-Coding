// Olympiad > �ѱ������ø��ǾƵ� > KOI 1997 > �ߵ�� 1��
// park03851���� �ڵ带 �Ϻ� �����Ͽ����ϴ�: https://www.acmicpc.net/board/view/33798
#include<iostream>
using namespace std;
int i, j, k, l, p, q, r, x, y, z, N, A[105];
int verif(int len)
{
	for (p = 2; p <= len / 2; p++) // �κм��� ����
		for (q = 1; q <= len - p; q++) // ���� �κм��� ���� ����
		{
			x = 0;
			for (r = q; r < q + p && r + p <= len; r++) // ���� �κм���( ����:[q,q+p) )�� ���� �κм���( ����:[q+p,q+2p) ) ���Ͽ� ���� �� ������ ���� �κм��� ����(p)�� ��ġ
				x += (A[r] == A[r + p]);
			if (x==p)
				return 0;
		}
	return 1;
}
void recurse(int M)
{
	if (M == N + 1)
	{
		for (i = 1; i <= N; i++)
			cout << A[i];
		exit(0);
	}

	for (int c = 1; c <= 3; c++) // ����Լ� �ȿ��� �������� ���� �� ������ ���Ѵ�!
	{
		if (A[M - 1] == c) // �ٷ� ���� �Ͱ� �ߺ��Ǵ� ���; ���� verif() ȣ�⿡�� ��� ������� �߻���Ű�� �ͺ��� ���⼭ �Ÿ��� ���� �� ����
			continue;
		A[M] = c;
		if (verif(M)) recurse(M + 1);
	}
}
int main()
{
	cin >> N;
	recurse(1);
	return 0;
}