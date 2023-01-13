/* 기초 알고리즘(탐색과 정렬) - 4. 문장만들기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define MAX_LENGTH 10005

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* line = (char*)calloc(MAX_LENGTH, sizeof(char));
	fgets(line, MAX_LENGTH, in);

	fprintf(out, "%s\n", line);

	int loops = 0;
	while (true)
	{
		// Lookup-table based occurrence counter
		int countTable[200] = { 0 };
		char lookupTable[200] = { 0 };
		int lookupTableIndex = 0;

		int len = strlen(line);
		if (len <= 0) break;
		for (int i = 0; i < len; i++)
		{
			char ch = line[i];

			if (ch < 'a' || ch > 'z') continue;
			
			int index = -1;
			for (int j = 0; j < lookupTableIndex; j++)
				if (lookupTable[j] == ch)
				{
					index = j;
					break;
				}
			
			if (index == -1)
				lookupTable[index = lookupTableIndex++] = ch;
			countTable[index]++;
		}

		char maxChar = '\0';
		int maxCount = 0;
		for (int i = 0; i < lookupTableIndex; i++)
		{
			int count = countTable[i];
			if (count * 200 + 50 - lookupTable[i] > maxCount * 200 + 50 - maxChar)
			{
				maxCount = count;
				maxChar = lookupTable[i];

				//printf("[L#%d] Chose char '%c' (cnt=%d, chr=%d, score=%d)\n", loops, maxChar, maxCount, maxChar, maxCount * 200 + 50 - maxChar);

			}
		}

		if (maxChar == '\0') break;

		char* whiteboard = (char*)calloc(MAX_LENGTH, sizeof(char));
		int wbIndex = 0;
		for (int j = 0; j < len; j++)
			if (line[j] != maxChar)
				whiteboard[wbIndex++] = line[j];
		strcpy(line, whiteboard);
		free(whiteboard);

		fprintf(out, "%s\n", line);

		loops++;
	}
	free(line);

	fclose(in);
	fclose(out);
	return 0;
}
