/* 기초 알고리즘(수학) - 6. 이집티안분수 */

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

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	int deno = 1, numer = 1;
	fscanf(in, "%d %d", &numer, &deno);
	fraction frac = { deno, numer };

	int nfracs = 0;
	fraction* fracs = (fraction*)calloc(1000, sizeof fraction);

	while (true)
	{
		fraction frac2 = { guf(frac.toF()), 1 };
		printf("frac1=%.4f frac2=%.4f\n", frac.toF(), frac2.toF());
		if (frac.numerator > 0)
		{
			printf("try: %d/%d\n", frac2.numerator, frac2.denominator);
			fracs[nfracs++] = frac2;

			// 통분하고 빼는 것 구현
			int _lcm = lcm(frac.denominator, frac2.denominator);

			printf("lcm=%d\n", _lcm);
			int firstMult = _lcm / frac.denominator;
			int secondMult = _lcm / frac2.denominator;
			int subtractedNumerator = frac.numerator * firstMult - secondMult; // frac2 numerator is always 1
			frac.numerator = subtractedNumerator;
			frac.denominator = _lcm;
			printf("frac=%d/%d\n", frac.numerator, frac.denominator);
		}
		else break;
	}

	fracs[nfracs++] = frac;


	FILE* out = fopen("OUTPUT.TXT", "w");

	for (int i = 0; i < nfracs; i++)
	{
		if (i == nfracs - 1 || i + 1 <= nfracs && fracs[i + 1].numerator <= 0)
			fprintf(out, "%d/%d", fracs[i].numerator, fracs[i].denominator);
		else
			fprintf(out, "%d/%d+", fracs[i].numerator, fracs[i].denominator);
	}

	fclose(in);
	fclose(out);
	return 0;
}
