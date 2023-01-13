/* 기초 알고리즘(스택 & 큐) - 2. 연설 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int ch;
	int nestedLevel = 0;
	while ((ch = fgetc(in)) != EOF)
	{
		if (ch == '(')
			nestedLevel++;
		else if (ch == ')')
		{
			nestedLevel--;
			if (nestedLevel < 0)
				printf("WARN: Unmatched parenthese");
		}
		else
		{

			if (nestedLevel % 2 == 1)
				ch = toupper(ch);

			fputc(ch, out);
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
