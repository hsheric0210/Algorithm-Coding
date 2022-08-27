/* 중급(上) 17. 이진수의표현 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0, i;
	fscanf(in, "%d", &n);

	char pos[32] = { 0 };
	int posIndex = -1;

	for (i = 31; i >= 0; i--)
	{
		if ((n & (1 << i)) != 0)
		{
			printf("found at %d (%d)\n", i, 1 << i);
			if (posIndex < 0)
				posIndex = 0;
			pos[posIndex++] = '1';
		}
		else if (posIndex >= 0)
			pos[posIndex++] = '0';
	}

	int oneIndexes[32] = { 0 };
	int oneIndex = 0;

	for (i = 0; i < 32; i++)
	{
		if (pos[i] == '1')
		{
			oneIndexes[oneIndex++] = i + 1;
			printf("found one at %d\n", i + 1);
		}
	}

	for (i = 0; i < oneIndex; i++)
	{
		if (i == oneIndex - 1)
			fprintf(out, "%d", oneIndexes[i]);
		else
			fprintf(out, "%d ", oneIndexes[i]);
	}

	fclose(in);
	fclose(out);
	return 0;
}
