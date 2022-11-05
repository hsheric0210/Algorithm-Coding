/* 기초 알고리즘(탐색과 정렬) - 1. Gas Station Numbers */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <deque>
#include <algorithm>

#define MAX_LEN 40

int endOfIncrementPoint(int len, char* line)
{
	// search in back-to-front
	int previous = 0, i = len - 1;
	for (; i >= 0; i--)
	{
		if (line[i] == '.') continue;
		int n = line[i] - '0';
		if (n == 2)
			n = 5;
		else if (n == 6)
			n = 9;
		if (n >= previous)
			previous = n;
		else
			break;
	}
	return i;
}

int main(void)
{
	char* line = (char*)calloc(MAX_LEN, sizeof(char));
	if (line == nullptr)
	{
		printf("warn: line alloc fail.\n");
		return 1;
	}

	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	fgets(line, MAX_LEN, in);
	fclose(in);

	int len = strlen(line);

	int ep = endOfIncrementPoint(len, line);
	//printf("ep index = %d (value=%c)\n", ep, line[ep]);

	int pivot = line[ep] - '0';
	std::deque<int> dq;
	for (int i = ep; i < len; i++)
		if (line[i] != '.')
			dq.push_back(line[i] - '0');

	for (int i = 0; i < ep; i++)
		fprintf(out, "%c", line[i]);

	// check if unavailable
	int prev = 0;
	bool unable = ep == -1;

	if (unable)
		fputs("The price cannot be raised.", out);
	else
		for (int i = ep; i < len - 1; i++)
		{
			int found = -1;
			for (int j = pivot + 1; j < 10; j++) // j: needle (search target)
			{
				// DUMP DQ ELEMENTS
				printf("[trying j %d] dq elems:", j);
				for (auto k = dq.begin(); k != dq.end(); k++)
					printf(" %d", *k);
				printf("\n");
				// DUMP DQ ELEMENTS

				for (auto k = dq.begin(); k != dq.end(); k++)
				{
					int value = *k;
					if (value == j || value == 6 && j == 9 || value == 9 && j == 6 || value == 2 && j == 5 || value == 5 && j == 2)
					{
						found = j;
						dq.erase(k);
						printf("found %d (on elem %d)\n", j, value);
						break;
					}
				}
				if (found >= 0)
					break;
			}
			// 강제로 마지막으로부터 두 번째 원소와 마지막 원소 사이에 점 삽입
			if (i == len - 2)
				fprintf(out, ".");
			fprintf(out, "%d", found);
			pivot = 0;
		}

	fclose(out);
	return 0;
}
