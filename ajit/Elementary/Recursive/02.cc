/* 기초 알고리즘(재귀호출) - 2. 고집수 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <deque>

int splitAndMultiply(int v, int n, int recursionDepth)
{
	int cnt = log10(n) + 1;
	if (n == 0 || cnt == 1) return recursionDepth;

	int mul = 1;
	for (int i = 0; i < cnt; i++)
	{
		int nu = n / (int)pow(10, i) % 10;
		mul *= nu;
	}
#ifdef DBGPRINT
	printf("[%dr%d] %d -> %d\n", v, recursionDepth, n, mul);
#endif DBGPRINT

	return splitAndMultiply(v, mul, recursionDepth + 1);
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int min = 0, max = 0, n = 0;
	fscanf(in, "%d %d %d", &min, &max, &n);
	fclose(in);

	int* nums = (int*)calloc(max - min + 1, sizeof(int));
	int numIdx = 0;
	for (int i = min; i <= max; i++) {
		int r = splitAndMultiply(i, i, 0);
#ifdef DBGPRINT
		printf("%d -> %d\n", i, r);
#endif
		if (r == n)
			nums[numIdx++] = i;
	}

	fprintf(out, "%d\n", numIdx);
	for (int i = 0; i < numIdx; i++)
		fprintf(out, "%d\n", nums[i]);
	free(nums);

	fclose(out);
	return 0;
}
