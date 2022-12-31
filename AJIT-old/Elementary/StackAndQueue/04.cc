/* 기초 알고리즘(스택 & 큐) - 4. 카드 읽기 순서 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool cardcmpinternal(int len, char* first, char* second, int offset)
{
	for (int i = 0; i < len; i++)
		if (first[(i + offset) % len] != second[i])
			return false;
	return true;
}

bool cardcmp(int len, char* first, char* second)
{
	if (len <= 0) return  true;

	int flag = 0;
	for (int k = 0; k < 2; k++) // two-pass comparison
	{
		for (int j = 0; j < len; j++) // offset increment loop (brute force)
		{
			if (cardcmpinternal(len, first, second, j))
				return true;
		}
		_strrev(second); // reverse second after first pass
	}

	return false;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int len = 0;
	fscanf(in, "%d", &len);
	
	char* cards = (char*)calloc(len + 1, sizeof(char)); // 1 for null terminator
	fscanf(in, "%s", cards);

	int nComparatee = 0;
	fscanf(in, "%d", &nComparatee);
	for (int i = 0; i < nComparatee; i++)
	{
		char* comparatee = (char*)calloc(len + 1, sizeof(char)); // 1 for null terminator
		fscanf(in, "%s", comparatee);

		if (cardcmp(len, cards, comparatee))
			fprintf(out, "Y\n");
		else
			fprintf(out, "N\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
