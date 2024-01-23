/* 기초 알고리즘(수학) - 8. 갈비 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

bool isPrime(int n)
{
	if (n == 1) return false;
	for (int i = sqrt(n); i > 1; i--)
		if (n % i == 0)
			return false;
	return true;
}

bool isPrimeGalbi(int num)
{
	int cnt = (int)log10(num);
	for (int i = 0; i <= cnt; i++)
	{
		if (!isPrime(num))
			return false;
		num /= 10;
	}
	return true;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int n = 0;
	fscanf(in, "%d", &n);

	FILE* out = fopen("OUTPUT.TXT", "w");

	int start = (int)pow(10, n - 1);
	int end = (int)pow(10, n);

	for (int i = start; i < end; i++)
		if (isPrimeGalbi(i))
			fprintf(out, "%d\n", i);

	fclose(in);
	fclose(out);
	return 0;
}
