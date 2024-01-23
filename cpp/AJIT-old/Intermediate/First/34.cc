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

	int line, col, center = (scale - 1) / 2;
	for (line = 0; line < scale; line++)
	{
		int blanks;
		if (line <= center)
			blanks = line * 2 - 1;
		else
			blanks = ((scale - 1) * 2) - (line + 1) * 2 + 1;

		int blankOrigin = (scale - blanks) / 2 - 1;
		int blankBound = blankOrigin + blanks;

		for (col = 0; col < scale; col++)
		{
			if (blankOrigin < col && col <= blankBound)
				fprintf(out, "-");
			else
				fprintf(out, "*");
		}
		fprintf(out, "\n");
	}
		
	fclose(in);
	fclose(out);
	return 0;
}
