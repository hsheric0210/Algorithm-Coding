#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");


	int scale;
	fscanf(in, "%d", &scale);

	int i, j, k, center = (scale - 1) / 2;
	for (i = 0; i < scale; i++)
	{
		if (i <= center)
			k = i + 1;
		else
			k = scale - i;
		for (j = 0; j < k; j++)
			fprintf(out, "*");
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
