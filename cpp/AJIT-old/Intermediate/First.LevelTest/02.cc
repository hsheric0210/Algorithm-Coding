/* 중급(下) 레벨테스트 2. 사칙연산 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int a = 0, b = 0;
	char op = '\0';
	fscanf(in, "%d", &a);
	fscanf(in, " %c", &op);
	fscanf(in, "%d", &b);
	
	float result = 0;
	bool err = false;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a - b;
		break;
	case '/':
		if (b == 0)
		{
			err = true;
			fprintf(out, "IMPOSSIBLE");
		}
		result = (float)a / (float)b;
		break;
	}

	if (!err);
	fprintf(out, "%.2f", result);

	fclose(in);
	fclose(out);
	return 0;
}
