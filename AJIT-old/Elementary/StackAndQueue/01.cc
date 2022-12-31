/* 기초 알고리즘(스택 & 큐) - 1. 얼음왕국 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char ch = '\0';
	while ((ch = fgetc(in)) != '.')
	{
		if (ch == 'h' || ch == 'y' || ch == 'a')
			continue;
		fputc(ch, out);
	}
	fputc('.', out);

	fclose(in);
	fclose(out);
	return 0;
}
