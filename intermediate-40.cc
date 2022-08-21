#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int num;
	fscanf(in, "%d", &num);

	int i, j = 0;
	if (num > 1)
	for (i = 2; i <= (int)ceil(sqrt(num)); i++)
	{
		if (num % i == 0)
		{
			fprintf(out, "NO");
			j = 1;
			break;
		}
	}

	if (num <= 1)
		fprintf(out, "NO");
	else if (j == 0)
		fprintf(out, "YES");

	fclose(in);
	fclose(out);
	return 0;
}
