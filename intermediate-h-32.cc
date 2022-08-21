/* �߱�(߾) 32. ���ڿ����� */

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
	int resultIndex = 0;

	int nestedLevel = 0;

	for (int i = 0; i < len; i++)
	{
		char ch = line[i];
		if (ch == '[')
			nestedLevel++;
		else if (ch == ']' && nestedLevel > 0)
			nestedLevel--;
		else if (nestedLevel == 0)
			result[resultIndex++] = ch;
	}

	fputs(result, out);

	fclose(in);
	fclose(out);
	return 0;
}
