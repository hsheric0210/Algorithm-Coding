/* 기초 알고리즘(수학) - 1. 숫자사슬 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>
#include <algorithm>

int arr2i(int* arr, int len)
{
	int value = 0;
	for (int i = 0; i < len; i++)
		value += arr[i] * (int)pow(10, len - i - 1);
	return value;
}

int* i2arr(int value, int* len)
{
	*len = (int)log10(value) + 1;
	int* arr = (int*)calloc(*len, sizeof(int));
	for (int i = 0; i < *len; i++)
		arr[i] = value / (int)pow(10, *len - i - 1) % 10;
	return arr;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0, len = 0;
	fscanf(in, "%d", &n);

	std::deque<int> nq

	//test//
	printf("input num: %d\n", n);
	int l_test = 0;
	int* test = i2arr(n, &l_test);
	for (int i = 0; i < l_test; i++)
		printf("i2arr result [%d]: %d\n", i, test[i]);
	int reconv_test = arr2i(test, l_test);
	printf("arr2i result: %d\n", reconv_test);
	//test//

	int* chain = (int*)calloc(10000, sizeof(int));
	int chain_pos = 0;

	int length = 0;
	bool first = true;
	while (true)
	{
		int* arr = i2arr(n, &len);
		int* arr2 = (int*)calloc(len, sizeof(int));
		memcpy(arr2, arr, sizeof(int) * len);
		std::sort(arr, arr + len, std::less<int>());
		std::sort(arr2, arr2 + len, std::greater<int>());

		int sub = arr2i(arr, len);
		int new_n = arr2i(arr2, len) - sub;
		if (first)
		{
			chain[chain_pos++] = sub;
			printf("initial chain = %d\n", sub);
			first = false;
		}
		length++;
		
		bool already_exists = false;
		for (int i = 0; i < length; i++)
		{
			if (chain[i] == new_n)
			{
				already_exists = true;
				printf("chain %d already exists at index %d!\n", new_n, i);
				break;
			}
		}
		if (already_exists)
			break;
		n = new_n;
		printf("chain #%d = %d\n", chain_pos, n);
		chain[chain_pos++] = n;

		free(arr);
		free(arr2);
	}

	fprintf(out, "%d\n", length);
	for (int i = 0; i < chain_pos; i++)
		fprintf(out, "%d\n", chain[i]);

	fclose(out);
	return 0;
}
