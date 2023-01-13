/* 중급(上) 27. 반올림 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// API 사용, 90점
int roundAt(int input, int places)
{
	return (int)(rint((double)input / places) * places);
}

// 직접 구현, 100점
int roundAt2(int input, int places)
{
	int mod = input % places;
	int first = mod / (places / 10);
	if (first >= 5)
		return input + (places - mod);
	return input - mod;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%u", &n);

	int i = 0;
	int pwr = 10;
	for (i = 1; i <= 3; i++)
	{
		fprintf(out, "%u\n", roundAt2(n, pwr));
		pwr *= 10;
	}

	fclose(in);
	fclose(out);
	return 0;
}
