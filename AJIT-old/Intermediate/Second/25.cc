/* 중급(上) 25. 달팽이 안의 문자 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scale = 0;

void putArr(int** arr, int _x, int _y, int value)
{
	int x = _x, y = _y;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= scale)
		x = scale - 1;
	if (y >= scale)
		y = scale - 1;
#ifdef DBG
	printf("arr[%d(%d)][%d(%d)] = %d\n", x, _x, y, _y, value);
#endif
	arr[x][y] = value;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int initial = 0, arrX = 1, arrY = 1, i, j;
	fscanf(in, "%d %d %d %d", &initial, &scale, &arrX, &arrY);

	int** arr = (int**)calloc(scale, sizeof(int*));
	for (i = 0; i < scale; i++)
		arr[i] = (int*)calloc(scale, sizeof(int));

	// step: 0=left 1=right 2=left 3=up
	int step = 0;
	int stepSize = scale;
	int number = initial;
	int rowPos = 0, colPos = 0;
	for (i = 0; i < scale * scale; i++)
	{
		//printf("Performing step %d [stepSize=%d, num=%d, fromRow=%d, fromCol=%d]\n", step, stepSize, number, rowPos, colPos);
		int m, n;
		switch (step)
		{
		case 0:
			// left
			for (m = 0; m < stepSize; m++)
				putArr(arr, colPos, rowPos + m, number++);
			rowPos += stepSize - 1;
			colPos++;
			break;
		case 1:
			// down
			for (m = 0; m < stepSize; m++)
				putArr(arr, colPos + m, rowPos, number++);
			rowPos--;
			colPos += stepSize - 1;
			break;
		case 2:
			// right
			for (m = 0; m < stepSize; m++)
				putArr(arr, colPos, rowPos - m, number++);
			rowPos -= stepSize - 1;
			colPos--;
			break;
		case 3:
			// up
			for (m = 0; m < stepSize; m++)
				putArr(arr, colPos - m, rowPos, number++);
			rowPos++;
			colPos -= stepSize - 1;
			break;
		}

		step++;
		if (step >= 4)
			step = 0;

		if (i % 2 == 0)
			stepSize--;
	}

	for (i = 0; i < scale; i++)
	{
		for (j = 0; j < scale; j++)
		{
			if (j == scale - 1)
				printf("%2d", arr[i][j]);
			else
				printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}

	fprintf(out, "%d", arr[arrX - 1][arrY - 1]);

	for (i = 0; i < scale; i++)
		free(arr[i]);
	free(arr);

	fclose(in);
	fclose(out);
	return 0;
}
