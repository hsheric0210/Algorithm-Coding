/* Áß±Þ(ß¾) 10. modulo */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int lookup[10] = { 0 };
	int lookupSize = 0;

	int i, j;
	for (i = 0; i < 10; i++)
	{
		int n;
		fscanf(in, "%d", &n);

		int mod = n % 42;
		
		int index = -1;
		if (lookupSize > 0)
		{
			for (j = 0; j < lookupSize; j++)
				if (lookup[j] == mod)
				{
					index = j;
					break;
				}
		}
		if (index < 0)
		{
			lookup[lookupSize++] = mod;
		}
	}

	fprintf(out, "%d", lookupSize);

	fclose(in);
	fclose(out);
	return 0;
}
