/* 중급(上) 29. 숫자의 분할 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 100

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* buffer = (char*)calloc(MAX_LENGTH, sizeof(char));
	fgets(buffer, MAX_LENGTH, in);

	int i, len = strlen(buffer);
	for (i = len - 1; i >= 0; i--)
	{
		fprintf(out, "%s ", buffer + i);
	}
	

	fclose(in);
	fclose(out);
	return 0;
}
