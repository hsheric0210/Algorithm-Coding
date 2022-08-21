/* Áß±Þ(ß¾) 11. findprime */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int reqIndex = -1, i, number, k, isPrime, index = 0;
	fscanf(in, "%d", &reqIndex);

	for (int nLoop = 1;; nLoop++)
	{
		isPrime = 1;
		number = nLoop * 4 + 1;
		for (k = 2; k <= (int)ceil(sqrt(number)); k++)
		{
			if (number % k == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime && ++index == reqIndex)
		{
			fprintf(out, "%d", number);
			break;
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
