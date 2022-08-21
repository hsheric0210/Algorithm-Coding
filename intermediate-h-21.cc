/* Áß±Þ(ß¾) 21. RLE */
/* Á¡¼ö: 90 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define COMPRESSED_LEN 310
#define UNCOMPRESSED_LEN 2000
 
char parseRLE(char* src, int *dstCount)
{
	char nStart = src[0];
	char n = src[1] - 0x30; // parse int 
	char nBound = src[2];
	char repChar = src[3];
	if (nStart == '(' && n > 0 && n <= 9 && nBound == ')')
	{
		*dstCount = n;
		return repChar;
	}

	return NULL;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	// char line[MAX_LEN] = { 0 };
	char line[COMPRESSED_LEN] = { 0 };
	fgets(line, COMPRESSED_LEN, in);
	int len = strlen(line);

	char uncompressed[UNCOMPRESSED_LEN] = { 0 };
	int uncompressed_index = 0;

	int i;
	for (i = 0; i < len; i++)
	{
		// Copy w/o null-terminator
		char buffer[4] = { 0 };
		const int copyLen = 4;
		memcpy(buffer, line + i, copyLen * sizeof(char));

		int count = 0;
		char ch = parseRLE(buffer, &count);
		if (ch == NULL || count <= 0)
		{
			char buf = line[i];
			printf("not-in-format '%c' at offset %d\n", buf, i);
			uncompressed[uncompressed_index++] = buf;
		}
		else
		{
			printf("parsed '%c' * %d at offset %d len 4\n", ch, count, i);
			int j;
			for (j = 0; j < count; j++)
				uncompressed[uncompressed_index++] = ch;
			i += 3; // Skip already parsed elements
		}
	}

	fputs(uncompressed, out);


	fclose(in);
	fclose(out);
	return 0;
}
