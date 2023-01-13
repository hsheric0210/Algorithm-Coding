/* 중급(上) 1. 알파벳 문자 개수 세기 */

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
	int len = strlen(line);

	int counts[26] = { 0 };

	int i;
	for (i = 0; i < len; i++)
	{
		char ch = line[i];
		if (!isalpha(ch)) continue;
		if (islower(ch))
			ch = toupper(ch);

		counts[ch - 'A']++;
	}

	for (i = 0; i < 26; i++)
	{
		fprintf(out, "%c %d\n", i + 'A', counts[i]);
	}

	fclose(in);
	fclose(out);
	return 0;
}
