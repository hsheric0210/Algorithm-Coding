// Olympiad > 한국정보올림피아드 > KOI 2002 > 고등부 1번: 로봇 조종하기
// 아래왼, 아래오 2개 경우 나누는 DP 이용 풀이
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

	// I. 첫 번째 열은 항상 아래, 또는 오른쪽으로만 갈 수 있음 ( (1,1)에서 시작하기에 )
	for (i = 0; i <= M; i++)
		DP[1][i + 1] += DP[1][i] + MAP[1][i + 1];

	// II. 두 번째 열부터 DP수행
	for (i = 2; i <= N; i++)
	{
		// (1) Left vs Down
		A[1] = DP[i - 1][1] + MAP[i][1]; // 왼쪽 첫번째 -> 위에서 내려오는 것만 가능
		for (j = 2; j <= M; j++) A[j] = max(DP[i - 1][j], A[j - 1]) + MAP[i][j];

		// (2) Right vs Down
		B[M] = DP[i - 1][M] + MAP[i][M]; // 오른쪽 맨 마지막 -> 위에서 내려오는 것만 가능
		for (j = M - 1; j > 0; j--) B[j] = max(DP[i - 1][j], B[j + 1]) + MAP[i][j];

		// (3) (1), (2) 중 최대를 현재 열 DP에 저장
		for (j = 1; j <= M; j++) DP[i][j] = max(A[j], B[j]);
	}
	cout << DP[N][M];
	return 0;
}