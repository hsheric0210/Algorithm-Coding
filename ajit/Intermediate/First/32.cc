#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	
	int scale;
	fscanf(in, "%d", &scale);

	int line, count, blankCount, dotCount;
	for (line = 0; line <= scale * 2; line++)
	{
		if (line == scale)
		{
			// special case
			blankCount = 0;
			dotCount = 0;

			for (count = 0; count < scale; count++)
				fprintf(out, "* ");
			fprintf(out, "*");
		}
		else if (line < scale)
		{
			blankCount = scale - line - 1;
			dotCount = line + 1;
		}
		else
		{
			blankCount = line - scale - 1;
			dotCount = scale * 2 - line + 1;
		}

		printf("line[%d] = blank %d dot %d\n", line, blankCount, dotCount);

		for (count = 0; count < blankCount; count++)
			fprintf(out, " ");
		for (count = 0; count < dotCount; count++)
			fprintf(out, " *");
		fprintf(out, "\n");
	}
		
	fclose(in);
	fclose(out);
	return 0;
}
