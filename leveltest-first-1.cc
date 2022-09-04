/* 중급(下) 레벨테스트 1. Financial Management */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	float sum = 0;
	for (int i = 0; i < 12; i++)
	{
		float f = 0;
		fscanf(in, "%f", &f);
		sum += f;
	}
	fprintf(out, "%.2f", sum / 12);

	fclose(in);
	fclose(out);
	return 0;
}
