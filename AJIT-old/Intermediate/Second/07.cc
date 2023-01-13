/* 중급(上) 7. 큰수의뺄셈 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int i;
	char first[MAX_LEN] = { 0 };
	char second[MAX_LEN] = { 0 };
	char result[MAX_LEN] = { 0 };

	fgets(first, MAX_LEN, in);
	fgets(second, MAX_LEN, in);

	int nfirst = strlen(first);
	int nsecond = strlen(second);

	printf("first %s\n", first);
	printf("second %s\n", second);

	int remain = 0;
	for (i = nfirst - 2; i >= 0; i--)
	{
		int f = 0, s = 0;
		if (isdigit(first[i]))
			f = first[i] - 0x30;
		int sindex = nsecond - 1 - (nfirst - 2 - i);
		printf("loop cnt %d sidx %d\n", nfirst - 2 - i, sindex);
		if (sindex >= 0 && nsecond > sindex && isdigit(second[sindex]))
			s = second[sindex] - 0x30;

		if (remain)
		{
			if (f > 0)
			{
				f--;
				remain = 0;
			}
			else
				f = 9;
		}

		if (f < s)
		{
			remain = 1;
			result[i] = 10 + f - s + 0x30;
		}
		else
			result[i] = f - s + 0x30;
		printf("#%d f=%d s=%d res=%d\n", i, f, s, f - s);
	}

	int rstlen = strlen(result), zero = 1;
	for (i = 0; i < rstlen; i++)
	{
		if (zero && result[i] != '0')
			zero = 0;
		if (!zero)
			fprintf(out, "%c", result[i]);
	}

	fclose(in);
	fclose(out);
	return 0;
}
