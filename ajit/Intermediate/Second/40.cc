/* 중급(上) 40. 숫자 마름모 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int m = 0, n = 0;
	fscanf(in, "%d %d", &m, &n);

	int lines = m * 2 - 1;
	int maxblanks = (m - 1) * 2;

	// draw blank lines
	for (int i = 0; i < lines; i++)
	{
		int blanks, numbers;
		if (i <= m - 1)
		{
			blanks = maxblanks - i * 2;
			numbers = i * 2 + 1;
		}
		else
		{
			blanks = (i - m + 1) * 2;
			numbers = (m - 1) * 2 - (i - (m - 1)) * 2 + 1;
		}
		for (int j = 0; j < blanks; j++)
			fprintf(out, " ");
		int num = n + 1;
		for (int j = 0; j < numbers; j++)
		{
			if (j <= (numbers - 1) / 2)
				num--;
			else
				num++;
			if (num < 0)
				num += 10;
			if (num >= 10)
				num -= 10;
			fprintf(out, "%d ", num);
		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
