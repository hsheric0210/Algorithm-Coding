#include<iostream>
using namespace std;
int i, j, k, l, A[105], N, p, q, r, s, t, u, v;

//����§�ڵ�
int verify(int n)
{
	for (p = 2; p <= n / 2; p++) // Ž���� �κм��� ����
		for (q = 1; q <= n - p; q++) // ù ��° �κм��� ���� ��ġ
		{
			s = 0;
			for (r = q; r < q + p; r++) // ���� �˻�
			{
				if (r + p > n)break; //prevent reading uninitialized part of sequence
				s += (A[r] == A[r + p]);
			}
			if (s==p) return 0; // �κм��� �ߺ�!
		}
	return 1;
}
int recurse(int idx)
{
	if (idx == N + 1)
	{
		for (i = 1; i <= N; i++)
			cout << A[i];
		exit(0);
	}

	for (i = 1; i <= 3; i++)
	{
		if (i == A[idx - 1])continue;
		A[idx] = i;
		if (check(idx)) { recurse(idx + 1); cout << "next rec\n"; }
	}
}
//����§�ڵ�

//�������ڵ�
int check(int len)
{
	int c;

	for (int i = 2; i <= len / 2; i++) {
		for (int j = 1; j <= len - i; j++) {
			c = 0;
			for (int k = j; k < j + i; k++)
				if (A[k] == A[k + i]) c++;

			if (c == i) return 0;
		}
	}
	return 1;
}
void go(int cnt) {
	if (cnt == N + 1) {
		for (j = 1; j <= N; j++) cout<<A[j];
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		if (i == A[cnt - 1]) continue; // 2���̻� �����̸� �ٷ� �Ÿ�
		A[cnt] = i;
		if (verify(cnt)) go(cnt + 1);
	}
}
//�������ڵ�

int main()
{
	cin >> N;
	//for (i = 1; i <= N; i++)
	//{
	//	for (j = 1; j <= 3; j++)
	//	{
	//		if (A[i - 1] != j)
	//			A[i] = j;
	//		if (!verify(i)) continue;
	//	}
	//}
	//for (i = 1; i <= N; i++)
	//	cout << A[i];
	go(1);
	return 0;
}