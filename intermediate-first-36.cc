#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");


	int lineCount, i;
	fscanf(in, "%d", &lineCount);

	char** values = (char**)malloc(lineCount * sizeof(char));
	int rowCountMax = 0;

	// Drop first line (
	char* dummy = (char*)malloc(MAXLEN * sizeof(char));
	fgets(dummy, MAXLEN, in);
	free(dummy);

	for (i = 0; i < lineCount; i++)
	{
		char* row = (char*)malloc(MAXLEN * sizeof(char));
		fgets(row, MAXLEN, in);
		int len = strlen(row);
		if (rowCountMax < len)
			rowCountMax = len;
		values[i] = row;
	}
	
	int j;
	for (i = 0; i < rowCountMax; i++)
	{
		for (j = 0; j < lineCount; j++)
		{
			char ch = values[j][i];
			if (isascii(ch) && isalnum(ch))
				fprintf(out, "%c", ch);
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
