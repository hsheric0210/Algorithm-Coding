/* 중급(上) 14. 소트인사이드 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = -1, i;
	fscanf(in, "%d", &n);

	int digits = (int)log10(n);
	printf("digits=%d\n", digits + 1);
	int* digitArr = (int*)calloc(digits + 1, sizeof(int));
	for (i = digits; i >= 0; i--)
	{
		int digit = (n / (int)pow(10, i)) % 10;
		digitArr[i] = digit;
		printf("digit at %d is %d\n", i, digit);
	}

	std::sort(digitArr, digitArr + digits + 1, std::less<int>());

	for (i = 0; i <= digits; i++)
		fputc(digitArr[i] + 0x30, out);

	fclose(in);
	fclose(out);
	return 0;
}
