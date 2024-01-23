/* 기초 알고리즘(재귀호출) - 1. 나비효과수열 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <deque>

void butterfly(FILE *f, int n)
{
	if (n <= 0) return;

	if (n == 1)
	{
		fprintf(f, "%d ", 1);
	}
	else
	{
		fprintf(f, "%d ", n);
		butterfly(f, n - 1);
		butterfly(f, n - 2);
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);
	fclose(in);

	std::deque<int> seq;
	butterfly(out, n);
	fclose(out);
	return 0;
}
