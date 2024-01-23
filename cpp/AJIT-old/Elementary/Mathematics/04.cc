/* 기초 알고리즘(수학) - 4. 몇진수일까 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char radix_char_arr[36] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

int parse(int radix, int len, char* str)
{
	int result = 0;
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		int value = 0;
		if (ch >= '0' && ch <= '9')
			value = ch - '0';
		else if (ch >= 'A' && ch <= 'Z')
			value = ch - 'A' + 10;

		int weight = (int)pow(radix, len - i - 1);
		result += value * weight;
	}
	return result;
}

int predictMinimumRadix(int len, char* str)
{
	int rca_max = 0;
	for (int i = 0; i < len; i++)
	{
		char c = str[i];
		for (int j = 35; j >= 0; j--)
		{
			if (radix_char_arr[j] == c)
			{
				if (j > rca_max)
					rca_max = j;
				break;
			}
		}
	}
	return rca_max + 1;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	char* p = (char*)calloc(100, sizeof(char));
	char* q = (char*)calloc(100, sizeof(char));
	if (p == nullptr || q == nullptr)
	{
		printf("String heap array allocation failure.\n");
		fclose(in);
		return 1;
	}
	
	if (fscanf(in, "%s %s", p, q) != 2)
	{
		printf("Input mismatched. (%%d %%d)\n");
		fclose(in);
		return 2;
	}

	printf("Input: %s and %s\n", p, q);

	int lp = strlen(p);
	int lq = strlen(q);

	FILE* out = fopen("OUTPUT.TXT", "w");

	int pp = predictMinimumRadix(lp, p);
	int pq = predictMinimumRadix(lq, q);

	printf("Predicted min radix: p=%d(%c), q=%d(%c)\n", pp, radix_char_arr[pp - 1], pq, radix_char_arr[pq - 1]);

	bool brk = false;
	for (int i = pp; i <= 36; i++)
	{
		int np = parse(i, lp, p);
		for (int j = pq; j <= 36; j++)
		{
			int nq = parse(j, lq, q);
			if (np == nq)
			{
				fprintf(out, "%d %d", i, j);
				brk = true;
				break; 
			}

			// optimization
			if (np < nq)
				break;
		}
		if (brk)
			break;
	}

	if (!brk)
		fprintf(out, "0 0");

	fclose(in);
	fclose(out);
	free(p);
	free(q);
	return 0;
}
