/* 중급(上) 13. toilet */

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

	int minCount;
	if (n % 3 == 0)
		minCount = n / 3;
	else
		// 참고: (적어도 C에서는) 실수형 -> 정수형 변환 시 '소수점 아래가 사라진다.' 즉, "내림(floor)"된다.

		// 이는 정수끼리의 나눗셈에서도 마찬가지이다. 기본적으로 정수끼리의 나눗셈에서 몫이 실수가 나올 경우, "내림(floor)"되어 '몫과 나머지'연산을 한 것에서 '몫'만을 구한 것과 같은 결과가 나온다.
		// 즉, 'a / b' = 'div(a, b).quot'
		minCount = n / 3 + 1;
	int maxCount;
	if (n % 2 == 0)
		maxCount = n / 2;
	else
		maxCount = n / 2 + 1;
	fprintf(out, "%d %d", maxCount, minCount);

	fclose(in);
	fclose(out);
	return 0;
}
