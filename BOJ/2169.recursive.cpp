// Olympiad > �ѱ������ø��ǾƵ� > KOI 2002 > ���� 1��: �κ� �����ϱ�
// ��� DP�� �ÿ�
#include<iostream>
#include<algorithm>
#define DFLT -11235813
using namespace std;
int i, j, k, l, N, M, MAP[1005][1005], DP[1005][1005][4]; // 0,1,2�� DP, 3�� VISITED
int recurse(int, int, int);
int pushIfValid(int i, int j, int k)
{
	if (i >= 1 && i <= N && j >= 1 && j <= M && !DP[i][j][3])
		return recurse(i, j, k);
	return DFLT;
}
int recurse(int i, int j, int k)
{
	if (i == N && j == M) return MAP[i][j]; // ����!
	if (DP[i][j][k] != DFLT) return DP[i][j][k]; // �̹� ó���� ĭ ���� (�޸������̼�)
	DP[i][j][3] = 1; // �̹� Ž������ �̹� ���� �� ĭ�� �� �̻� Ž������ �ʵ��� VISITED �÷��� ����
	int x = pushIfValid(i + 1, j, 0),
		y = pushIfValid(i, j + 1, 1),
		z = pushIfValid(i, j - 1, 2);
	DP[i][j][3] = 0; // ���� Ž���� ���ؼ� VISITED �÷��� ����
	return DP[i][j][k] = MAP[i][j] + max({ x,y,z });
}
int main()
{
	cin >> N >> M;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
		{
			cin >> MAP[i][j];
			for (k = 0; k < 3; k++)
				DP[i][j][k] = DFLT;
		}
	cout << recurse(1, 1, 0);
	return 0;
}