/* 기초 알고리즘(스택 & 큐) - 9. Josephus Problem */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int n = 0, m = 0, k = 0;
	fscanf(in, "%d %d %d", &n, &m, &k);
	std::vector<int> warriors;
	for (int i = 0; i < n; i++)
		warriors.push_back(i + 1);
	FILE* out = fopen("OUTPUT.TXT", "w");
	 
	int exclude = m - 1;
	for (int i = 0; i < n - 1; i++)
	{ 
		printf("exclude@%d\n", exclude);
		fprintf(out, "%d ", *(warriors.begin() + exclude)); // print excluded warrior id
		warriors.erase(warriors.begin() + exclude);
		exclude += k - 1;
		exclude %= warriors.size();
	}
	fprintf(out, "\n%d", warriors.front()); // the last man standing

	fclose(in);
	fclose(out);
	return 0;
}
