// Olympiad > �ѱ������ø��ǾƵ� > KOI 2002 > ���� 1��: �κ� �����ϱ�
// �Ʒ���, �Ʒ��� 2�� ��� ������ DP �̿� Ǯ��
#include<iostream>
using namespace std;
int i, j, k, l, N, M, MAP[1005][1005], A[1005], B[1005], DP[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			cin >> MAP[i][j];

	// I. ù ��° ���� �׻� �Ʒ�, �Ǵ� ���������θ� �� �� ���� ( (1,1)���� �����ϱ⿡ )
	for (i = 0; i <= M; i++)
		DP[1][i + 1] += DP[1][i] + MAP[1][i + 1];

	// II. �� ��° ������ DP����
	for (i = 2; i <= N; i++)
	{
		// (1) Left vs Down
		A[1] = DP[i - 1][1] + MAP[i][1]; // ���� ù��° -> ������ �������� �͸� ����
		for (j = 2; j <= M; j++) A[j] = max(DP[i - 1][j], A[j - 1]) + MAP[i][j];

		// (2) Right vs Down
		B[M] = DP[i - 1][M] + MAP[i][M]; // ������ �� ������ -> ������ �������� �͸� ����
		for (j = M - 1; j > 0; j--) B[j] = max(DP[i - 1][j], B[j + 1]) + MAP[i][j];

		// (3) (1), (2) �� �ִ븦 ���� �� DP�� ����
		for (j = 1; j <= M; j++) DP[i][j] = max(A[j], B[j]);
	}
	cout << DP[N][M];
	return 0;
}