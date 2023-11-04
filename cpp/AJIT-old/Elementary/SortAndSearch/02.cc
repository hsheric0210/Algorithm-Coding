/* 기초 알고리즘(탐색과 정렬) - 2. 나폴레옹의 모자른 군사들 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>

int theLIS(int len, int* arr)
{
	int* LIS = (int*)calloc(len + 1, sizeof(int));
	LIS[0] = 0;
	for (int i = 1; i < len; i++)
	{
		int val = arr[i];
		int lisMAX = 0;
		for (int j = 0; j < i; j++)
			if (arr[j] < val && LIS[j] > lisMAX)
				lisMAX = LIS[j];
		LIS[i] = lisMAX + 1;
	}

	int max = 0;
	for (int i = 0; i < len; i++)
		if (LIS[i] > max)
			max = LIS[i];
	return max;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int cnt = 0;
	fscanf(in, "%d", &cnt);
	int* line = (int*)calloc(cnt, sizeof(int));
	for (int i = 0; i < cnt; i++)
		fscanf(in, "%d", line + i);

	int lisLen = theLIS(cnt, line);
	int* lineRev = (int*)calloc(cnt, sizeof(int));
	for (int i = 0; i < cnt; i++)
		lineRev[cnt - i - 1] = line[i];
	free(line);
	int revLisLen = theLIS(cnt, lineRev);
	free(lineRev);
	printf("LIS=%d LIS_rev=%d\n", lisLen, revLisLen);
	if (lisLen > revLisLen)
		fprintf(out, "LEFT");
	else if (lisLen < revLisLen)
		fprintf(out, "RIGHT");
	else
		fprintf(out, "IDGARA");

	fclose(in);
	fclose(out);
	return 0;
}
