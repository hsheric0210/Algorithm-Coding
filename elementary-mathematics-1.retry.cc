/* 기초 알고리즘(수학) - 1. 숫자사슬 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

typedef struct _ret {
	int len;
	int* asc;
	int* desc;
} ret;

ret f(int x)
{
	printf("f: in=%d\n", x);
	int i = 1;
	int* asc = (int*)calloc(11, sizeof(int));
	for (i = 0; x > 0; i++)
	{
		asc[i] = x % 10;
		x /= 10;
	}

	int* desc = (int*)calloc(i, sizeof(int));
	std::sort(asc, asc + i, std::less<int>());
	memcpy(desc, asc, sizeof(int) * i);
	std::reverse(desc, desc + i);

	printf("f:s l=%d\n", x, i);
	for (int j = 0; j < i; j++)
	{
		printf("f: #%d - asc=%d desc=%d\n", j, asc[j], desc[j]);
	}

	return { i, asc, desc };
}

int arr2i(int len, int* arr)
{
	int value = 0;
	for (int i = 0; i < len; i++)
		value += arr[i] * (int)pow(10, len - i - 1);
	return value;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);

	std::vector<int> nq;
	ret a = f(n);
	nq.push_back(n);

	int next = 0;
	while (true)
	{
		ret a = f(nq.back());
		int de = arr2i(a.len, a.desc);
		int as = arr2i(a.len, a.asc);
		next = de - as;

		printf("de: %d / as: %d\n", de, as);

		// conflict check
		bool conf = false;
		for (auto a = nq.cbegin(); a != nq.cend(); a++)
		{
			if (next == *a)
			{
				conf = true;
				break;
			}
		}
		if (conf)
			break;

		nq.push_back(next);
	}

	printf("chain_length: %d\n", nq.size());

	fprintf(out, "%d\n", nq.size());
	for (auto b = nq.cbegin(); b != nq.cend(); b++)
		fprintf(out, "%d\n", *b);

	fclose(out);
	return 0;
}
