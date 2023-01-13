/* 기초 알고리즘(다이나믹) - 1. 계단오르기 */

// TODO: Retry later

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <optional>
#include <vector>
#include <algorithm>

int a(int i)
{
	if (i < 0)
		return 0;
	if (i >= 0 && i <= 1)
		return 1;
	else if (i == 2)
		return 2;

	return a(i - 1) + a(i - 2) + a(i - 3);
}

int main(int argc, char** argv) {
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	int n = 0;
	fscanf(in, "%d", &n);
	fprintf(out, "%d", a(n));
	fclose(in);
	fclose(out);
}