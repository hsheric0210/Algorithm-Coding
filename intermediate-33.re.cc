#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	
	int scale;
	fscanf(in, "%d", &scale);

	int* numbers = (int*)calloc(scale * scale, sizeof(int));
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
