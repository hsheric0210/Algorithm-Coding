/*
문자열 구간뒤집기
https://43.200.211.173/contest/17/problem/80001
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
char* s;
int main()
{
	scanf("%d", &n);
	s = (char*)calloc(n, sizeof(char)); scanf("%s", s);
	scanf("%d", &m);
	for (int l = 0; l < m; l++)
	{
		// FIXME: i, j can be reversed
		int i, j; scanf("%d %d", &i, &j);
		int off = i - 1;
		int len = j - i + 1;
		char* sub = (char*)calloc(len + 1, sizeof(char));
		strncpy(sub, s + off, len);
		_strrev(sub);
		strncpy(s + off, sub, len);
		//free(sub);
	}
	printf("%s", s);
	return 0;
}