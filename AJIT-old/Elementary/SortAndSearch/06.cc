/* 기초 알고리즘(탐색과 정렬) - 6. 순위매기기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int value = 0;
		fscanf(in, "%d", &value);
		fprintf(out, "%d ", value);
		arr[i] = value;
	}
	fprintf(out, "\n");

	int* sorted = (int*)calloc(n, sizeof(int));
	int* orderArray = (int*)calloc(n, sizeof(int));
	memcpy(sorted, arr, n * sizeof(int));
	std::sort(sorted, sorted + n);

	for (int i = 0; i < n; i++)
	{
		int num = arr[i];
		int index = std::find(sorted, sorted + n, num) - sorted;
		fprintf(out, "%d ", index + 1);
	}

	fclose(in);
	fclose(out);
	return 0;
}
