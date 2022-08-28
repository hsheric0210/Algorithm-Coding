/* Áß±Þ(ß¾) 38. ±äÀÚ¸®¼öÀÇ°ö¼À */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 250

// TODO: Remove debug prints 

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* first = (char*)calloc(MAX_LENGTH, sizeof(char));
	char* second = (char*)calloc(MAX_LENGTH, sizeof(char));

	fgets(first, MAX_LENGTH, in);
	fgets(second, MAX_LENGTH, in);

	int nfirst = strlen(first) - 1; // exclude newline
	int nsecond = strlen(second);

	if (nsecond > nfirst)
	{
		//swap
		char* tmp = first;
		first = second;
		second = tmp;

		int ntmp = nfirst;
		nfirst = nsecond;
		nsecond = ntmp;
	}

	printf("flen: %d\nslen: %d\n", nfirst, nsecond);

	// TODO: optimize it
	int** arr = (int**)calloc(nsecond, sizeof(int*));
	if (arr != nullptr)
		for (int i = 0; i < nsecond; i++)
			arr[i] = (int*)calloc(MAX_LENGTH * 2, sizeof(int));

	// ¼¼·Î¼À
	for (int i = 0; i < nsecond; i++)
	{
		int secondvalue = second[nsecond - i - 1] - '0';

		for (int j = 0; j < nfirst; j++)
		{
			int firstvalue = first[nfirst - j - 1] - '0';
			int value = firstvalue * secondvalue;
			printf("#s%d f%d first: %d second: %d result: %d\n", i, j, firstvalue, secondvalue, value);

			int valueIndex = MAX_LENGTH * 2 - j - i - 1;
			int carryIndex = valueIndex - 1;
			arr[i][valueIndex] += value;

			int newvalue = arr[i][valueIndex];
			if (newvalue >= 10)
			{
				int carrying = newvalue / 10;
				newvalue %= 10;
				arr[i][valueIndex] = newvalue;
				arr[i][carryIndex] += carrying;
				printf("carrying: %d result: %d\n", carrying, newvalue);
			}
		}
	}

	for (int i = 0; i < nsecond; i++)
	{
		printf("#%d -> ", i);
		for (int j = 0; j < MAX_LENGTH * 2; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	// ¼¼·Î¼À µ¡¼À °è»ê

	char* result = (char*)calloc(MAX_LENGTH * 2, sizeof(char));
	if (result == nullptr)
	{
		printf("result allocation failure\n");
		return 1;
	}

	for (int col = 0; col < MAX_LENGTH * 2 - 1; col++)
	{
		int sum = 0;
		for (int row = 0; row < nsecond; row++)
		{
			sum += arr[row][MAX_LENGTH * 2 - col - 1];
		}

		int valueIndex = MAX_LENGTH * 2 - col - 2;
		int carryIndex = valueIndex - 1;
		result[valueIndex] += sum;

		int newvalue = result[valueIndex];
		if (newvalue >= 10)
		{
			int carrying = newvalue / 10;
			newvalue %= 10;
			result[valueIndex] = newvalue;
			result[carryIndex] += carrying;
			printf("#%d - carrying: '%d' result: '%d'\n", col, carrying, newvalue);
		}
		printf("#%d - %d = %d\n", col, valueIndex, result[valueIndex]);
	}

	// convert to number
	for (int i = 0; i < MAX_LENGTH * 2 - 1; i++)
	{
		result[i] += '0';
	}

	free(arr);

	// strip leading zeros
	int index = 0;
	for (int i = 0; i < MAX_LENGTH * 2; i++)
	{
		if (result[i] != '0')
		{
			index = i;
			break;
		}
	}

	fputs(result + index, out);
	free(result);

	free(first);
	free(second);

	fclose(in);
	fclose(out);
	return 0;
}
