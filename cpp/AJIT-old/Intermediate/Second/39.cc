/* 중급(上) 39. 독감 예방주사 맞기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

void shift(int* arr, int length, int amount)
{
	// memcpy가 제대로 작동하지 않아서 그냥 직접 구현함
	int* copy = (int*)calloc(amount, sizeof(int));
	for (int i = 0; i < amount; i++)
		copy[i] = arr[i + length - amount - 1];

	arr[length - amount - 1] = arr[length - 1];

	for (int i = 0; i < amount; i++)
		arr[i + length - amount] = copy[i];
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int size = 0;
	fscanf(in, "%d", &size);

	int test1[7] = { 1,2,3,4,5, 6, 7 };
	shift(test1, 7, 2);
	for (int i = 0; i < 7; i++)
		printf("%d\n", test1[i]);

	int* arr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		int shiftAmount = 0;
		fscanf(in, "%d", &shiftAmount);

		arr[i] = i + 1;
		shift(arr, i + 1, shiftAmount);
	}

	for (int i = 0; i < size; i++)
		fprintf(out, "%d ", arr[i]);

	fclose(in);
	fclose(out);
	return 0;
}
