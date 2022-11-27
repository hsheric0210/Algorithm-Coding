/* 기초 알고리즘(스택 & 큐) - 5. 다각형 그리기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool cardcmpinternal(int len, int* first, int* second, int offset)
{
	for (int i = 0; i < len; i++)
	{
		int idx = (i + offset) % len;
		if (first[idx] != second[i])
		{
			return false;
		}
	}
	return true;
}

int opposite(int dir)
{
	switch (dir)
	{
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 1;
		break;
	case 4:
		return 2;
	}
}

bool cardcmp(int len, int* first, int* second)
{
	if (len <= 0) return  true;

	int* third = (int*)malloc(len * sizeof(int));
	if (third == nullptr)
	{
		printf("third alloc fail");
		return false;
	}

	// k=0 : normal check
	// k=1 : normal opposite check
	// k=2 : reversed check
	// k=3 : reversed opposite check
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < len; i++)
		{
			// opposite direction
			int val = second[k >= 2 ? (len - i - 1) : i];
			if (k % 2 == 1)
				val = opposite(val);
			third[i] = val;
		}

		for (int j = 0; j < len; j++) // offset increment loop (brute force)
		{
			if (cardcmpinternal(len, first, k == 0 ? second : third, j))
				return true;
		}
	}

	return false;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int len = 0;
	fscanf(in, "%d", &len);

	int* cards = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
		fscanf(in, "%d", cards + i);

	int nComparatee = 0;
	fscanf(in, "%d", &nComparatee);

	int nPossible = 0;
	int** possible = (int**)calloc(nComparatee, sizeof(int*));
	for (int i = 0; i < nComparatee; i++)
		possible[i] = (int*)calloc(len, sizeof(int));
	for (int i = 0; i < nComparatee; i++)
	{
		int* comparatee = (int*)calloc(len, sizeof(int));
		for (int j = 0; j < len; j++)
			fscanf(in, "%d", comparatee + j);

		if (cardcmp(len, cards, comparatee))
		{
			printf("possible @ %d\n", i);
			memcpy(possible[nPossible++], comparatee, len * sizeof(int));
		}
	}

	fprintf(out, "%d\n", nPossible);
	for (int i = 0; i < nPossible; i++)
	{
		for (int j = 0; j < len; j++)
			fprintf(out, "%d ", possible[i][j]);
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
