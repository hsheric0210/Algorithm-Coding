/* 중급(上) 32. 문자열제거 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* line = (char*)calloc(MAX_LENGTH, sizeof(char));
	fgets(line, MAX_LENGTH, in);
	int len = strlen(line);

	char* result = (char*)calloc(MAX_LENGTH, sizeof(char));
	if (result == NULL)
	{
		printf("memory allocation failure\n");
		return 1;
	}

	int resultIndex = 0;

	int nestedLevel = 0;

	for (int i = 0; i < len; i++)
	{
		char ch = line[i];
		if (ch == '[')
			nestedLevel++;
		else if (ch == ']')
			nestedLevel--;
		else if (nestedLevel == 0)
			result[resultIndex++] = ch;
	}

	fputs(result, out);

	fclose(in);
	fclose(out);
	return 0;
}
