/* Áß±Þ(ß¾) 38. ±äÀÚ¸®¼öÀÇ°ö¼À */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 250

#undef _VERT_DBG
#undef _ARR_DMP
#define _SUM_DBG

// TODO: Remove debug prints 

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* first = (char*)calloc(MAX_LENGTH, sizeof(char));
	char* second = (char*)calloc(MAX_LENGTH, sizeof(char));

	// Read numbers
	fgets(first, MAX_LENGTH, in);
	fgets(second, MAX_LENGTH, in);

	int nfirst = strlen(first) - 1; // newline excluded
	int nsecond = strlen(second);

	// first always larger than second
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


#ifdef _ARR_DMP
	printf("[INPUT] first_length=%d\nsecond_length: %d\n", nfirst, nsecond);
#endif

	// ¼¼·Î¼À °è»êÀ» À§ÇÑ ¹è¿­
	// TODO: optimize it
	int** arr = (int**)calloc(nsecond, sizeof(int*));
	if (arr != nullptr)
		for (int i = 0; i < nsecond; i++)
			arr[i] = (int*)calloc(MAX_LENGTH * 2, sizeof(int));
	if (arr == nullptr)
	{
		printf("[alloc] arr allocation failure\n");
		return 1;
	}

	// ¼¼·Î¼À ½ÇÇà
	for (int i = 0; i < nsecond; i++)
	{
		int secondvalue = second[nsecond - i - 1] - '0';

		for (int j = 0; j < nfirst; j++)
		{
			int firstvalue = first[nfirst - j - 1] - '0';
			int timesResult = firstvalue * secondvalue;
#ifdef _VERT_DBG
			printf("[VERT] #s%d f%d first: %d second: %d result: %d\n", i, j, firstvalue, secondvalue, timesResult);
#endif

			int valueIndex = MAX_LENGTH * 2 - j - i - 1;
			int carryIndex = valueIndex - 1;
			arr[i][valueIndex] += timesResult;

			int carryTimes = 1;
			while (arr[i][valueIndex] >= 10)
			{
				carryIndex = valueIndex - 1;
				int carrying = arr[i][valueIndex] / 10;
#ifdef _VERT_DBG
				printf("[VERT-CARRY] %d-th carry: '%d' -> %d ... %d\n", carryTimes, arr[i][valueIndex], carrying, arr[i][valueIndex] % 10);
#endif
				arr[i][valueIndex] %= 10; // fix overflow
				
				arr[i][carryIndex] += carrying;
				carryTimes++;
				valueIndex--;
				// used 'while' statement to check if the overflow occurred at carryIndex by carrying
			}
		}
	}

#ifdef _ARR_DMP
	for (int i = 0; i < nsecond; i++)
	{
		printf("[ARR-DMP] #%d -> ", i);
		for (int j = 0; j < MAX_LENGTH * 2; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
#endif

	// ¼¼·Î¼À µ¡¼À °è»ê

	char* result = (char*)calloc(MAX_LENGTH * 2, sizeof(char));
	_strset(result, 0);
	if (result == nullptr)
	{
		printf("[alloc] result allocation failure\n");
		return 1;
	}

	for (int col = 0; col < MAX_LENGTH * 2 - 1; col++)
	{
		int sum = 0;
		for (int row = 0; row < nsecond; row++)
		{
			int index = MAX_LENGTH * 2 - col - 1;
#ifdef _SUM_DBG
			if (arr[row][index] != 0)
				printf("[SUM-PART] row=#%d index=%d value=%d\n", row, index, arr[row][index]);
#endif
			if (arr[row][index] > 0)
			sum += arr[row][index];
		}

		int valueIndex = MAX_LENGTH * 2 - col - 2;
		int carryIndex = valueIndex - 1;
		result[valueIndex] += sum;

#ifdef _SUM_DBG
		printf("[SUM] sum=%d\n", sum);
#endif

		int carryTimes = 1;
		while (result[valueIndex] >= 10)
		{
			int carryValueLength = (int)log10(result[valueIndex]);
			for (int ci = 0; ci < carryValueLength; ci++)
			{
				carryIndex = valueIndex - 1;
				int carrying = result[valueIndex] / 10;
#ifdef _SUM_DBG
				printf("[SUM-CARRY] %d-th carrying: '%d' -> #%d %d ... %d\n", carryTimes, result[valueIndex], ci, carrying, result[valueIndex] % 10);
#endif
				result[valueIndex] %= 10; // fix overflow
				result[carryIndex] += carrying;
				carryTimes++;
				valueIndex--;
			}
			// used 'while' statement to check if the overflow occurred at carryIndex by carrying
		}

#ifdef _SUM_DBG
		int orig_index = MAX_LENGTH * 2 - col - 2;
		printf("[SUM] column #%d vindex=%d result=%d\n", col, orig_index, result[orig_index]);
#endif
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
