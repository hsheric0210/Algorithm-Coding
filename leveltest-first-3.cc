/* 중급(下) 레벨테스트 3. 최소공배수 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

int findGCD(int a, int b)
{
	int gcd = b;
	while (true)
	{
		b = a % gcd;
		if (b == 0)
			return gcd;
		a = gcd;
		gcd = b;
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int count = 0;
	fscanf(in, "%d", &count);
	int prev = 0;
	fscanf(in, "%d", &prev);
	for (int i = 0; i < count - 1; i++)
	{
		int next = 0;
		fscanf(in, "%d", &next);

		prev = prev * (next / findGCD(prev, next));
	}

	fprintf(out, "%d", prev);

	fclose(in);
	fclose(out);
	return 0;
}
