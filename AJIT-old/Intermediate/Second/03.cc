/* 중급(上) 3. 운석 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define min(x,y) (((x) < (y)) ? (x) : (y))
int depthInternal(int scale, int centerStart, int centerEnd, int column, int row)
{
	int scaleEven = scale % 2 == 0, center = scaleEven ? scale / 2 : scale - 1 / 2;
	if (column <= centerStart && row <= centerStart) // 좌상단
		return min(row, column) + 1;
	else if (column >= centerEnd && row <= centerEnd) // 우상단
		return min(row + 1, scale - column);
	else if (column <= centerStart && row >= centerEnd) // 좌하단
		return min(scale - row, column + 1);
	else if (column >= centerEnd && row >= centerEnd) // 우하단
		return min(scale - row, scale - column);
	return 0;
}

int depth(int scale, int column, int row)
{
	if (scale % 2 == 0) // Scale이 짝수 : 중앙값이 4개
		return depthInternal(scale, scale / 2 - 1, scale / 2, column, row);

	// Scale이 홀수 : 중앙값이 1개
	int center = (scale - 1) / 2;
	return depthInternal(scale, center, center, column, row);
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int scale, i, j;
	fscanf(in, "%d", &scale);

	int totalWeight = 0;

	for (i = 0; i < scale; i++)
	{
		for (j = 0; j < scale; j++)
		{
			int weight = 0;
			int dist = depth(scale, i, j);
			fscanf(in, "%d", &weight);
			printf("%02d ", dist);
			totalWeight += dist * weight;
		}
		printf("\n");
	}

	fprintf(out, "%d", totalWeight);

	fclose(in);
	fclose(out);
	return 0;
}