/* 기초 알고리즘(재귀호출) - 3. 대홍수 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>

std::set<int> visited;

int findRegion(int* arr, int arrSize, int x, int y)
{
	if (x < 0 || y < 0 || x >= arrSize || y >= arrSize || visited.find(y * arrSize + x) != visited.end() || arr[y * arrSize + x] > 0)
		return 0;

	visited.insert(y * arrSize + x);
	printf("chk %d %d (%d)\n", x, y, y*arrSize+x);

	int sum = 1;
	sum += findRegion(arr, arrSize, x + 1, y);
	sum += findRegion(arr, arrSize, x - 1, y);
	sum += findRegion(arr, arrSize, x, y + 1);
	sum += findRegion(arr, arrSize, x, y - 1); 
	return sum;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int size = 0, startX = 0, startY = 0;
	fscanf(in, "%d %d %d", &size, &startX, &startY);
	int* arr = (int*)calloc(size * size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fscanf(in, "%d", arr + j * size + i);
		}
	}
	fclose(in);

	int cnt = findRegion(arr, size, startX - 1, startY - 1);
	fprintf(out, "%d", cnt);
	fclose(out);
	return 0;
}
