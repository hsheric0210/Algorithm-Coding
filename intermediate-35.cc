#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 10000

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* scratch = (char*)calloc(MAXLEN, sizeof(char));
	fgets(scratch, MAXLEN, in);
	int length = strlen(scratch);

	char target[] = "khazix";
	int targetLen = 6;

	int i, matchProgress = 0, matchingCount = 0, retry = 0;
	for (i = 0; i < length; )
	{
		printf("check equality between scratch[%d](%c) == target[%d](%c)", i, scratch[i], matchProgress, target[matchProgress]);
		if (scratch[i] == target[matchProgress])
		{
			printf("met expected: %c (= %c) [prog %d]\n", scratch[i], target[matchProgress], matchProgress);
			if (++matchProgress == targetLen)
			{
				matchingCount++;
				matchProgress = 0;
			}
			retry = 0;
		}
		else
		{
			retry = !retry && matchProgress > 0;
			matchProgress = 0;
			printf("met unexpected: %c\n", scratch[i]);
		}
		if (!retry)
			i++;
	}

	fprintf(out, "%d", matchingCount);

	fclose(in);
	fclose(out);
	return 0;
}
