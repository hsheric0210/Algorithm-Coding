/* 기초 알고리즘(수학) - 7. 이집티안분수 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

typedef struct _fraction {
	int denominator, numerator;

	float toF()
	{
		return numerator / (float)denominator;
	}
} fraction;

int gcd(int a, int b)
{
	int gcd = b;
	while (true)
	{
		gcd = a % b;
		if (gcd == 0)
			return b;
		a = b;
		b = gcd;
	}
	return -1;
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int guf(float frac)
{
	if (frac == 0) return 0;
	int i;
	for (i = 2; 1.0f / i > frac; i++);
	return i;
}

fraction subtract(fraction a, fraction b)
{
	// 통분하고 빼는 것 구현
	int _lcm = lcm(a.denominator, b.denominator);
	int firstMult = _lcm / a.denominator;
	int secondMult = _lcm / b.denominator;
	return { _lcm, a.numerator * firstMult - b.numerator * secondMult };
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	int deno = 1, numer = 1;
	fscanf(in, "%d %d", &numer, &deno);
	fraction frac = { deno, numer };

	FILE* out = fopen("OUTPUT.TXT", "w");

	for (int i = 2; ; i++)
	{
		fraction frac2 = { i, 1 };
		fraction sub = subtract(frac, frac2);
		float f = frac.numerator * frac2.denominator - frac.denominator;
		if (f > 0)
		{
			// confirm and continue
			fprintf(out, "%d/%d+", frac2.numerator, frac2.denominator);
			frac = sub;
		}
		else if (f == 0)
		{
			// confirm and finish
			fprintf(out, "%d/%d", frac2.numerator, frac2.denominator);
			break;
		}
		else
		{
			// continue
			continue;
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
