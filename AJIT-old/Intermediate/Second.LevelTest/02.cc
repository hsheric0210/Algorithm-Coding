/* 중급(上) 레벨테스트 2. RLE */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 305

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* buffer = (char*)calloc(MAX_LENGTH, sizeof(char));
	fgets(buffer, MAX_LENGTH, in);
	int len = strlen(buffer);
	
	char* resultBuffer = (char*)calloc(len * 10, sizeof(char));
	int resultBufferPos = 0;

	for (int i = 0; i < len; i++)
	{
		if (i + 3 <= len - 1 /* overflow failsafe */ && buffer[i] == '(' && isdigit(buffer[i + 1]) && buffer[i + 2] == ')')
		{
			int count = buffer[i + 1] - '0';
			char ch = buffer[i + 3];
			for (int i = 0; i < count; i++)
			{
				resultBuffer[resultBufferPos++] = ch;
			}
			i += 3;
		}
		else
			resultBuffer[resultBufferPos++] = buffer[i];
	}

	fputs(resultBuffer, out);

	fclose(in);
	fclose(out);
	return 0;
}
