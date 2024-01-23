/* 중급(上) 15. 매직키테트리스 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void debugPrint(int screenWidth, int screenHeight, char* status, const char *phaseName)
{
	int height, width;
	printf("DEBUG PRINT @ PHASE %s\n", phaseName);
	for (height = 0; height < screenHeight; height++)
	{
		for (width = 0; width < screenWidth; width++)
		{
			printf("%c", status[height * screenHeight + width]);
		}
		printf("\n");
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int screenWidth = 0, screenHeight = 0;
	fscanf(in, "%d %d", &screenHeight, &screenWidth);

	char* status = (char*)calloc(screenWidth * screenHeight, sizeof(int));
	int height, width;
	for (height = 0; height < screenHeight; height++)
	{
		for (width = 0; width < screenWidth; )
		{
			char ch = '\0';
			fscanf(in, "%c", &ch);
			if (isdigit(ch))
			{
				status[height * screenHeight + width] = ch;
				width++;
			}
		}
	}

	debugPrint(screenWidth, screenHeight, status, "READ");

	// Apply 'magic key'
	for (width = 0; width < screenWidth; width++)
	{
		int nonBlankLine = 0;
		for (height = screenHeight - 1; height >= 0; height--)
		{
			// Skip the blank lines
			if (status[height * screenHeight + width] == '1')
				nonBlankLine++;
		}

		for (height = screenHeight - nonBlankLine; height < screenHeight; height++)
			status[height * screenHeight + width] = '1';

		for (height = 0; height < screenHeight - nonBlankLine; height++)
			status[height * screenHeight + width] = '0';
	}

	debugPrint(screenWidth, screenHeight, status, "APPLY");

	// Check clear
	int clearLine = 0;
	for (height = 0; height < screenHeight; height++)
	{
		int isFullLine = 1;
		for (width = 0; width < screenWidth; width++)
		{
			if (status[height * screenHeight + width] == '0')
			{
				isFullLine = 0;
				break;
			}
		}

		if (isFullLine)
		{
			// Clear the line (prevent current line to be printed)
			clearLine++;
		}
	}

	debugPrint(screenWidth, screenHeight, status, "UPDATE");

	for (height = 0; height < clearLine; height++)
	{
		for (width = 0; width < screenWidth; width++)
			fprintf(out, "0");
		fprintf(out, "\n");
	}

	for (height = 0; height < screenHeight - clearLine; height++)
	{
		for (width = 0; width < screenWidth; width++)
			fprintf(out, "%c", status[height * screenHeight + width]);
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
