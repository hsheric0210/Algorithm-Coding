/* 중급(上) 31. 마방진구하기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _pos {
	int column, row;

	struct _pos add(struct _pos offset)
	{
		return { column + offset.column, row + offset.row };
	}
} pos;

typedef struct _overflow {
	bool column, row;
} overflow;

bool isFullyFilled(int** arr, int scale)
{
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			if (arr[i][j] <= 0)
				return false;
		}
	}

	return true;
}

overflow checkOverflow(pos head, int scale)
{
	return { head.column < 0 || head.column >= scale, head.row < 0 || head.row >= scale };
}

void printDebug(int** arr, int scale)
{
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
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

	int counter = 1;
	pos head = { 0, 1 };
	do
	{
		// move diagonally
		head = { head.column + 1, head.row - 1 };

		// check bounds
		while (true)
		{
			printf("head(%d, %d)\n", head.row, head.column);
			overflow over = checkOverflow(head, scale);

			if (over.column && over.row)
			{
				head.column -= 1;
				head.row -= 2;
				continue;
			}

			if (over.column)
			{
				head.column = scale - 1;
				continue;
			}

			if (over.row)
			{
				head.row = 0;
				continue;
			}

			if (arr[head.column][head.row] > 0)
			{
				head.column -= 1;
				head.row -= 2;
				continue;
			}

			break;
		}

		arr[head.row][head.column] = counter++;

		printf("num: %d\n", counter);
		printDebug(arr, scale);
	} while (!isFullyFilled(arr, scale));

	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
