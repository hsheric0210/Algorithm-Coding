/* 중급(上) 12. 중간수 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = -1, i;
	fscanf(in, "%d", &n);

	int leftSum = 0, rightSum = 0;
	for (i = 1; i < n; i++)
	{
		leftSum += i;
		printf("%d ", i);
	}
	printf("= %d\n", leftSum);
	for (i = n + 1;; i++)
	{
		rightSum += i;
		printf("%d ", i);
		if (rightSum >= leftSum)
		{
			printf("= %d\n", rightSum);
			fputc(rightSum == leftSum ? 'O' : 'X', out);
			break;
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
