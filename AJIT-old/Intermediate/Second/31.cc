/* 중급(上) 31. 마방진구하기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool isFull(int scale, int** arr)
{
	for (int i = 0; i < scale; i++)
		for (int j = 0; j < scale; j++)
			if (arr[i][j] == 0)
				return false;
	return true;
}

void dumpArray(int scale, int** arr)
{
	for (int i = 0; i < scale; i++)
	{
		printf("[#%d] ", i + 1);
		for (int j = 0; j < scale; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void fixOverflow(int scale, int* xpos, int* ypos)
{
	bool xover = *xpos >= scale;
	bool yover = *ypos < 0;

	if (xover && yover)
	{
		*xpos -= 1;
		*ypos += 2;
	}
	else if (xover)
	{
		*xpos = 0;
	}
	else if (yover)
	{
		*ypos = scale - 1;
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int scale = 0;
	fscanf(in, "%d", &scale);

	int** arr = (int**)calloc(scale, sizeof(int*));
	for (int i = 0; i < scale; i++)
		arr[i] = (int*)calloc(scale, sizeof(int));

	int xpos = (scale - 1) / 2, ypos = 0, counter = 1;
	while (!isFull(scale, arr))
	{
		int prevX = xpos, prevY = ypos;

		// apply number
		arr[ypos][xpos] = counter++;

		// move cursor

		xpos++;
		ypos--;

		// fix overflow
		fixOverflow(scale, &xpos, &ypos);

		// check value overwrite
		if (arr[ypos][xpos] != 0)
		{
			xpos--;
			ypos += 2;
		}

		// re-check overflow
		fixOverflow(scale, &xpos, &ypos);

		//printf("[#%d] Source = (%d, %d), Destination = (%d, %d)\n", counter, prevX, prevY, xpos, ypos);
		//dumpArray(scale, arr);
	}

	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			if (j == scale - 1)
				fprintf(out, "%d", arr[i][j]);
			else
				fprintf(out, "%d ", arr[i][j]);
		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
