#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int lines, cols;
	fscanf(in, "%d %d", &cols, &lines);
	fgetc(in); // Drop line-break

	char chars[102][102] = { 0 };

	int i, j, k = 0, l = 0;
	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < cols; ) // include newline
		{
			char read;
			fscanf(in, "%c", &read);
			if (read == '*')
			{
				read = '#';
				k++;
			}
			else if (read == '@')
			{
				read = '&';
				l++;
			}
			else
				continue;
			chars[i][j] = read;
			j++;
		}
	}

	fprintf(out, "%d %d\n", k, l);
	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < cols; j++)
		{
			fprintf(out, "%c", chars[i][j]);
		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
