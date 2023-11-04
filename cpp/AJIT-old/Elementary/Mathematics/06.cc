/* 기초 알고리즘(수학) - 6. 주사위 쌓기 */
// 유형: Greedy

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int oppositeOf(int index)
{
	switch (index)
	{
	case 0:
		return 5;
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 1;
	case 4:
		return 2;
	case 5:
		return 0;
	}
}

int findMax(int len, int* arr, int exception1, int exception2)
{
	int maxValue = -1;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > maxValue && i != exception1 && i != exception2)
			maxValue = arr[i];
	}
	return maxValue;
}

int findMaxIndex(int len, int* arr, int exception1, int exception2)
{
	int maxValue = -1;
	int maxIndex = -1;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > maxValue && i != exception1 && i != exception2)
		{
			maxValue = arr[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

int findMinIndex(int len, int* arr, int exception1, int exception2)
{
	int minValue = 999;
	int minIndex = -1;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < minValue && i != exception1 && i != exception2)
		{
			minValue = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int indexOf(int len, int* arr, int needle)
{
	for (int i = 0; i < len; i++)
		if (arr[i] == needle)
			return i;
	return -1;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int diceCounts = 0;
	fscanf(in, "%d", &diceCounts);

	int** dices = (int**)calloc(diceCounts, sizeof(int*));
	for (int i = 0; i < diceCounts; i++)
		dices[i] = (int*)calloc(6, sizeof(int));
	
	// read face numbers
	for (int i = 0; i < diceCounts; i++)
		for (int j = 0; j < 6; j++)
			if (fscanf(in, " %d", &dices[i][j]) != 1)
				printf("input err");

	int previousTop = -1, sum = 0;
	int maxIndex = findMaxIndex(6, dices[0], -1, -1);
	int maxOpposIndex = oppositeOf(maxIndex);

	int maxValue = -1;
	// try for all faces (except max and its opposite one)
	for (int k = 0; k < 6; k++)
	{
		// exclusion
		//if (k == maxIndex || k == maxOpposIndex) continue;

		previousTop = dices[0][k];
		int downIndex = oppositeOf(k);

		// find max for entry dice (first dice)
		int max = findMax(6, dices[0], k, downIndex);
		sum += max;

		// perform greedy
		for (int n = 1; n < diceCounts; n++)
		{
			int bottomFaceIndex = indexOf(6, dices[n], previousTop);
			int topFaceIndex = oppositeOf(bottomFaceIndex);


			int max = findMax(6, dices[n], bottomFaceIndex, topFaceIndex);
			sum += max;

			previousTop = dices[n][topFaceIndex];
		}

		// retrieve result
		if (maxValue < sum)
			maxValue = sum;
		sum = 0;
	}

	FILE* out = fopen("OUTPUT.TXT", "w");

	// write result
	fprintf(out, "%d", maxValue);

	// free heaps
	for (int i = 0; i < diceCounts; i++)
		free(dices[i]);
	free(dices);

	fclose(in);
	fclose(out);
	return 0;
}
