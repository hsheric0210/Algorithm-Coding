// Olympiad > 한국정보올림피아드 > KOI 1997 > 중등부 1번
// park03851님의 코드를 일부 참고하였습니다: https://www.acmicpc.net/board/view/33798
#include<iostream>
using namespace std;
int i, j, k, l, p, q, r, x, y, z, N, A[105];
int verif(int len)
{
	for (p = 2; p <= len / 2; p++) // 부분수열 길이
		for (q = 1; q <= len - p; q++) // 앞쪽 부분수열 시작 지점
		{
			x = 0;
			for (r = q; r < q + p && r + p <= len; r++) // 앞쪽 부분수열( 범위:[q,q+p) )와 뒷쪽 부분수열( 범위:[q+p,q+2p) ) 비교하여 같은 것 개수가 실제 부분수열 길이(p)와 일치
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

	for (int c = 1; c <= 3; c++) // 재귀함수 안에서 전역변수 쓰면 값 꼬여서 망한다!
	{
		if (A[M - 1] == c) // 바로 이전 것과 중복되는 경우; 괜히 verif() 호출에서 재귀 오버헤드 발생시키는 것보다 여기서 거르는 것이 더 빠름
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