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


	int n, u, d, current = 0, elapsed = 0;
	fscanf(in, "%d %d %d", &n, &u, &d);

	int up = 1;
	do
	{
		if (up)
			current += u;
		else
			current -= d;
		up = !up;
		elapsed++;
	} while (current < n);

	fprintf(out, "%d", elapsed);

	fclose(in);
	fclose(out);
	return 0;
}
