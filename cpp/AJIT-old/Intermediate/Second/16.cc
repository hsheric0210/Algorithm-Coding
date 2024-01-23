/* 중급(上) 16. 문자열구간뒤집기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 102

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int revCount = 0;
	fscanf(in, "%d", &revCount); // Drop

	char line[MAX_LEN] = {0};
	fscanf(in, "%s", line);
	int strLength = strlen(line);

	fscanf(in, "%d", &revCount);

	printf("string %s lendth %d revcnt %d\n", line, strLength, revCount);

	int i; 
	for (i = 0; i < revCount; i++)
	{
		int revStart = 0, revEnd = 0;
		fscanf(in, "%d %d", &revStart, &revEnd);
		if (revStart > revEnd)
		{
			// Failsafe
			int tmp = revEnd;
			revEnd = revStart;
			revStart = tmp;
		}

		// char* substr = (char*)calloc(revEnd - revStart + 2, sizeof(char)); // +1 for null terminator
		char substr[MAX_LEN] = { 0 };
		strncpy(substr, line + revStart - 1, revEnd - revStart + 1);
		printf("reversal %d - substr: '%s'\n", i, substr);
		_strrev(substr);
		strncpy(line + revStart - 1, substr, revEnd - revStart + 1); // Drop null terminator
		// free(substr);
	}

	fputs(line, out);
	
	fclose(in);
	fclose(out);
	return 0;
}
