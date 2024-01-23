/* 중급(上) 19. encryption2 */
/* 점수: 90 */
/* 도움 필요: O */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <errno.h>

#define MAX_LEN 250
#define ROW_COUNT 6
#define BLANK_CHAR '*'
#define PADDING_CHAR '.'

bool decrypt(char* dst, char* src, int len)
{
	if (len % 6 > 0)
	{
		printf("ERROR: Padding size mismatch. (%d)\n", len);
		return false;
	}

	int arrLength = len / 6;

	printf("[DECRYPTION] column_size: %d\n", arrLength);

	int rowIndex, columnIndex, index = 0, dstIndex;
	for (rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < arrLength; columnIndex++)
		{
			char ch = src[index++];
			dstIndex = columnIndex * ROW_COUNT + rowIndex;
			if (ch == BLANK_CHAR)
				ch = ' ';
			else if (ch == PADDING_CHAR)
				ch = '\0'; // Apply null term.
			printf("[DECRYPTION] Char at index %d mapped to [R%d:C%d](= %d) is '%c'\n", index, rowIndex, columnIndex, dstIndex, ch);
			dst[dstIndex] = ch;
		}
	}

	// debug print
	printf("[DECRYPTION] result: ");
	for (rowIndex = 0; rowIndex < len; rowIndex++)
		printf("%c", dst[rowIndex]);
	printf("\n");
	// AB CD EFGH IJK LMNO PRST TUVI
	return true;
}

bool encrypt(char* dst, char* src, int len)
{
	div_t dv = div(len, 6);
	int columnCount = dv.quot + 1;
	int paddingSize = 6 - dv.rem % 6; // remove: this var is redundant

	printf("[ENCRYPTION] column_count: %d, padding_size: %d\n", columnCount, paddingSize);

	int rowIndex, columnIndex, dstIndex = 0;
	for (rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < columnCount; columnIndex++)
		{
			int srcIndex = columnIndex * ROW_COUNT + rowIndex;
			char ch = srcIndex < len ? src[srcIndex] : PADDING_CHAR; // prevent overrun
			if (ch == ' ')
				ch = BLANK_CHAR;
			printf("[ENCRYPTION] Char at [R%d:C%d](= %d) is '%c'\n", rowIndex, columnIndex, srcIndex, ch);
			dst[dstIndex++] = ch;
		}
	}

	// debug print
	printf("[ENCRYPTION] result: ");
	for (rowIndex = 0; rowIndex < dstIndex; rowIndex++)
		printf("%c", dst[rowIndex]);
	printf("\n");

	return true;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char line[MAX_LEN] = { 0 };
	fgets(line, MAX_LEN, in);
	int i, len = strlen(line);

	// check if the line contains blank char or padding
	bool isEncrypted = false;
	for (i = 0; i < len; i++)
	{
		if (line[i] == BLANK_CHAR || line[i] == PADDING_CHAR)
			isEncrypted = true;
	}

	char proceed[MAX_LEN] = { 0 };
	(isEncrypted ? decrypt : encrypt)(proceed, line, len); // Pointer conditional HACK
	fputs(proceed, out);

	fclose(in);
	fclose(out);
	return 0;
}
