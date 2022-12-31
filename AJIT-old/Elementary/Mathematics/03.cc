/* 기초 알고리즘(수학) - 3. 두수의나눗셈 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int a = 0, b = 0;
	if (fscanf(in, "%d %d", &a, &b) != 2)
	{
		printf("e: insufficient params\n");
		fclose(in);
		return 2;
	}

	FILE* out = fopen("OUTPUT.TXT", "w");

	int narr[21] = { 0 };
	narr[0] = (a >= b) ? (a / b) : 0;

	int lenchk = 0;
	for (int i = 1; lenchk < 20; i++)
	{
		int op = (int)pow(10, i);
		a *= op;
		int result = a / b % op;
		int nlen = i;
		for (int j = 0; j < nlen && lenchk < 20; j++)
		{
			int part = result / (int)pow(10, nlen - j - 1) % 10;
			int nxtPart = result / (nlen - j - 2 <= 0 ? 1 : ((int)pow(10, nlen - j - 2))) % 10;
			narr[lenchk + 1] = part;
			if (lenchk == 19 && nxtPart >= 5)
			{
				narr[lenchk + 1] += 1;
				for (int k = lenchk; narr[k + 1] >= 10 && k >= 0; k--)
				{
					narr[k + 1] %= 10;
					narr[k] += 1;
				}
			}
			lenchk++;
		}
		a = a % b;
	}

	fprintf(out, "%d.", narr[0]);
	for (int i = 1; i <= 20; i++)
	{
		fprintf(out, "%d", narr[i]);
	}

	fclose(in);
	fclose(out);
	return 0;
}
