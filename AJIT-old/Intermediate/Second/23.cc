/* 중급(上) 23. freq */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <math.h>

#define INITIAL_SIZE 5000
#define EXPAND_SIZE 2000
#define DEFAULT_BUFFER_OFFSET 100
#define STRING_BUFFER_EXTEND 5
#define CONV_RADIX 10

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int bound, needle;
	fscanf(in, "%d %d", &bound, &needle);

	int i;
	char* buffer = (char*)calloc(INITIAL_SIZE, sizeof(char));
	int bufferSize = INITIAL_SIZE;
	int bufferOffset = DEFAULT_BUFFER_OFFSET;
	memset(buffer, 0, bufferSize * sizeof(char));
	for (i = 1; i <= bound; i++)
	{
		char* numBuffer = (char*)calloc((int)log10(i) + STRING_BUFFER_EXTEND, sizeof(char));
		_itoa(i, numBuffer, CONV_RADIX);
		int len = strlen(numBuffer);
		if (bufferOffset + len >= bufferSize)
		{
			buffer = (char*)realloc(buffer, (bufferSize + EXPAND_SIZE) * sizeof(char));
			memset(buffer + bufferSize, 0, EXPAND_SIZE * sizeof(char)); // fill zero the newly-allocated area
			bufferSize += EXPAND_SIZE;
		}
		strcat(buffer, numBuffer);
		bufferOffset += len;
		free(numBuffer);
	}

	char* needleStr = (char*)calloc((int)log10(needle) + STRING_BUFFER_EXTEND, sizeof(char));
	_itoa(needle, needleStr, CONV_RADIX);

	// find the needle on the haystack
	int foundCount = 0;
	while ((buffer = strstr(buffer, needleStr)) != NULL)
	{
		printf("found needle at offset %d (pos: %p, %d)\n", buffer, *buffer);
		foundCount++;
		buffer++;
	}

	fprintf(out, "%d", foundCount);

	fclose(in);
	fclose(out);
	return 0;
}
