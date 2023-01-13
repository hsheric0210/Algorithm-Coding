/* 기초 알고리즘(스택 & 큐) - 10. 목걸이 문제 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 105

int main() {
	char* in_line = (char*)calloc(MAX_LEN, sizeof(char));
	char* line = (char*)calloc(MAX_LEN * 3, sizeof(char));
	FILE* in = fopen("INPUT.txt", "r");
	fgets(in_line, MAX_LEN, in);
	fclose(in);
	int len = strlen(in_line);
	strcpy(line, in_line);
	strcat(line, in_line);
	strcat(line, in_line);
	char pivot = 0;
	int max_count = 0, max_count_idx = 0;
	for (int i = len, j = len * 2 - 1; i <= j; i++)
	{
		int lcount = 0, rcount = 0;
		pivot = line[i];
		for (int j = i; j > i - len; j--)
		{
			if (line[j] == 'w')
				lcount++;
			else if (pivot == 'w')
			{
				pivot = line[j];
				lcount++;
			}
			else if (line[j] == pivot)
				lcount++;
			else break;
		}

		pivot = line[i + 1];
		for (int j = i + 1; j < i + len; j++)
		{
			if (line[j] == 'w')
				rcount++;
			else if (pivot == 'w')
			{
				pivot = line[j];
				rcount++;
			}
			else if (line[j] == pivot)
				rcount++;
			else break;
		}

		int sum = lcount + rcount;
		if (sum > max_count)
		{
			max_count = sum;
			max_count_idx = i - len + 1;
		}


		if (max_count > len) max_count = len;
	}
	int max_count_idx_end;
	if (max_count_idx < len)
		max_count_idx_end = max_count_idx + 1;
	else
		max_count_idx_end = 1;
	FILE* out = fopen("OUTPUT.txt", "w");
	fprintf(out, "%d %d %d", max_count, max_count_idx, max_count_idx_end);
	fclose(out);
	return 0;
}