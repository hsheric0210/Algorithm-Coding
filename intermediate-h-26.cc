/* 중급(上) 26. 대각선순으로배열값입력 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000
#define NOPRINT

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);

	// allocate at heap (allocation on stack will cause stack overflow)
	int i;
	int** arr = (int**)calloc(MAXSIZE, sizeof(int*));
	for (i = 0; i < MAXSIZE; i++)
		arr[i] = (int*)calloc(MAXSIZE, sizeof(int));

	int totalShantCount = n * 2 - 1;
	int shantIndex, limit = 0, revIndex = 0;
	int num = n - 1;
	for (shantIndex = 0; shantIndex < totalShantCount; shantIndex++)
	{
		int shantIndiceCount;
		if (shantIndex <= n - 1)
			shantIndiceCount = shantIndex + 1;
		else
			shantIndiceCount = totalShantCount - shantIndex;
		// render the shant
		if (shantIndex > n - 1)
		{
			revIndex++; 
			if (shantIndex == n)
				limit--;
		}

		int i;
		if (/*shantIndiceCount % 2 != 0*/true)
		{
			// Down to Up
#ifndef NOPRINT
			printf("#%d D2U ", shantIndex);
#endif
			for (i = 0; i < shantIndiceCount; i++)
			{
#ifndef NOPRINT
				printf("%d:arr[%d][%d] ", i, limit - i, i + revIndex);
#endif
				arr[limit - i][i + revIndex] = ++num;
			}
#ifndef  NOPRINT
			printf("\n");
#endif
		}
		else
		{
			// Up to Down
#ifndef NOPRINT
			printf("#%d U2D ", shantIndex);
#endif
			for (i = 0; i < shantIndiceCount; i++)
			{
#ifndef NOPRINT
				printf("%d:arr[%d][%d] ", i, i + revIndex, limit - i);
#endif
				arr[i + revIndex][limit - i] = ++num;
			}
#ifndef  NOPRINT
			printf("\n");
#endif
		}

		if (shantIndex <= n - 1)
			limit++;
	}

	int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
#ifdef DBG
			if (j == n - 1)
				fprintf(out, "%03d\n", arr[i][j]);
			else
				fprintf(out, "%03d ", arr[i][j]);
#else
			if (j == n - 1)
				fprintf(out, "%d\n", arr[i][j]);
			else
				fprintf(out, "%d ", arr[i][j]);
#endif
		}
	}

	for (i = 0; i < MAXSIZE; i++)
		free(arr[i]);
	free(arr);

	fclose(in);
	fclose(out);
	return 0;
}
