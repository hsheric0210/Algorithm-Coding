// Olympiad > 한국정보올림피아드 > KOI 1997 > 중등부 1번
#define _CRT_SECURE_NO_WARNINGS // 망할 VCRT
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
		if (!cmp(i - x + 1, i - x * 2 + 1, x)) // 길이 X짜리 부분수열 검사
			return true;
	return false;
}
int main()
{
	cin >> N;//ㅇㅗㅏㄴㅈㅓㄴㅌㅏㅁㅅㅐㄱ!
	// 하나하나 붙여나가며 부분수열 검사
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
		// all three failed the test -> 백트래킹하며 이전 수들 중 3이 아닌 첫 번째 수를 1 증가시키고 다시 시도
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