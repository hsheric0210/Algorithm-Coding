// Olympiad > 한국정보올림피아드 > KOI 2002 > 고등부 1번: 로봇 조종하기
// 재귀 DP를 시용
#include<iostream>
#include<algorithm>
#define DFLT -11235813
using namespace std;
int i, j, k, l, N, M, MAP[1005][1005], DP[1005][1005][4]; // 0,1,2은 DP, 3는 VISITED
int recurse(int, int, int);
int pushIfValid(int i, int j, int k)
{
	if (i >= 1 && i <= N && j >= 1 && j <= M && !DP[i][j][3])
		return recurse(i, j, k);
	return DFLT;
}
int recurse(int i, int j, int k)
{
	if (i == N && j == M) return MAP[i][j]; // 도착!
	if (DP[i][j][k] != DFLT) return DP[i][j][k]; // 이미 처리된 칸 제외 (메모이제이션)
	DP[i][j][3] = 1; // 이번 탐색에서 이미 지금 이 칸을 더 이상 탐색하지 않도록 VISITED 플래그 설정
	int x = pushIfValid(i + 1, j, 0),
		y = pushIfValid(i, j + 1, 1),
		z = pushIfValid(i, j - 1, 2);
	DP[i][j][3] = 0; // 다음 탐색을 위해서 VISITED 플래그 해제
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