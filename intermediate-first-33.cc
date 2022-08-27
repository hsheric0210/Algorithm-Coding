#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// TODO: Rewrite with "DYNAMIC PROGRAMMING"

void incrementCheck(int scale, int* arr, int realRow, int realCol)
{
	if (realRow < 0 || realRow >= scale || realCol < 0 || realCol >= scale)
		return;
	arr[scale * realRow + realCol]++;
	printf("Increment %d-%d\n", realRow, realCol);
}

void increment(int scale, int* arr, int row, int col)
{
	int rRange, cRange;
	for (rRange = -1; rRange <= 1; rRange++)
		for (cRange = -1; cRange <= 1; cRange++)
			incrementCheck(scale, arr, row + rRange, col + cRange);
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	
	int scale;
	fscanf(in, "%d", &scale);

	int* numbers = (int*)calloc(static_cast<size_t>(scale) * static_cast<size_t>(scale), sizeof(int));
	int row, col;
	for (row = 0; row < scale; row ++)
	{
		for (col = 0; col < scale;)
		{
			char c;
			fscanf(in, "%c", &c);
			printf("read: %c\n", c);
			if (c == '*')
			{
				printf("Found mine at %d-%d\n", row, col);
				increment(scale, numbers, row, col);
			}

			if (c == '0' || c == '*')
				col++;
		}
	}

	for (row = 0; row < scale; row++)
	{
		for (col = 0; col < scale; col++)
			fprintf(out, "%d", numbers[scale * row + col]);
		fprintf(out, "\n");
	}
		
	fclose(in);
	fclose(out);
	return 0;
}
