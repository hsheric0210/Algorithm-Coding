/* 중급(上) 5. 소인수분해 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define MAX_LEN 10000

// HELP: 해설 보고 풀음. 그런데 90점 ;

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = -1, i;
	fscanf(in, "%d", &n);

	int prevNumber = n;

	while (true)
	{
		for (i = 2; i <= (int)ceil(sqrt(n)); i++)
		{
			if (n % i == 0)
			{
				n /= i;
				printf("found %d! Now n is %d.\n", i, n);
				fprintf(out, "%d ", i);
				break;
			}
		}

		if (n == prevNumber)
		{
			fprintf(out, "%d", n);
			break; // number not changed = not found
		}
		prevNumber = n;
	}

	fclose(in);
	fclose(out);
	return 0;
}
