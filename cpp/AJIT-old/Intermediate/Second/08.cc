/* 중급(上) 8. stringcompression (문자열 압축) */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char line[MAX_LEN] = { 0 };
	fgets(line, MAX_LEN, in);

	int len = strlen(line), i;

	char prev = '\0';
	int dup = 0;
	for (i = 0; i <= len; i++)
	{
		if (i < len && prev == line[i])
		{
			dup++;
		}
		else if (prev != '\0')
		{
			if (dup >= 1)
				fprintf(out, "%d%c", dup + 1, prev);
			else
				fprintf(out, "%c", prev);
			dup = 0;
		}
		prev = line[i];
	}

	fclose(in);
	fclose(out);
	return 0;
}
