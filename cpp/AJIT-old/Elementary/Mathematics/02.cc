/* 기초 알고리즘(수학) - 2. 십자카드문제 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int* i2arr(int number, int& len)
{
	len = (int)log10(number) + 1;
	int* arr = (int*)calloc(len, sizeof(int));

	for (int i = 0; i < len; i++)
	{
		arr[i] = number / (int)pow(10, len - i - 1) % 10;
	}
	return arr;
}

int arr2i(int* arr, int len)
{
	int number = 0;
	for (int i = 0; i < len; i++)
	{
		number += arr[i] * (int)pow(10, len - i - 1);
	}
	return number;
}

int getClockNum(int num)
{
	int len = 0;
	int* arr = i2arr(num, len);
	int clocknums[4] = { 0 };
	for (int i = 0; i < 4; i++) 
	{
		// i = offset
		int arr2[4] = { 0 };
		for (int j = 0; j < 4; j++)
			arr2[j] = arr[(i + j) % len];
		clocknums[i] = arr2i(arr2, len);
	}

	int min = 0x7FFFFFFF;
	for (int i = 0; i < len; i++)
	{
		if (clocknums[i] < min)
			min = clocknums[i];
	}
	//printf("cnum = %d\n", min);
	return min;
}

int getOrdinal(int clocknum)
{
	int delta = 1;
	while (true)
	{
		if (clocknum == 1111)
			break;
		bool notclocknum = false;
		int len = 0;
		int* arr = i2arr(clocknum, len);
		for (int i = 0; i < 4; i++)
		{
			if (arr[i] == 0)
			{
				notclocknum = true;
				break;
			}
		}

		if (getClockNum(clocknum) < clocknum)
			notclocknum |= true;

		if (!notclocknum)
			delta++;
		//else
		//	printf("skipped zero (%d)\n", arr2i(arr, len));
		clocknum--;
	}

	return delta;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n[4] = { 0 };
	fscanf(in, "%d %d %d %d", n, n + 1, n + 2, n + 3);
	fprintf(out, "%d", getOrdinal(getClockNum(arr2i(n, 4))));

	fclose(in);
	fclose(out);
	return 0;
}
