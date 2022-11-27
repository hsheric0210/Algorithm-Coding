/* 기초 알고리즘(다이나믹) - 2. Give me the coin */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <optional>
#include <vector>
#include <algorithm>

int* arr;

int main(int argc, char** argv) {
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	int n = 0, m = 0;
	fscanf(in, "%d %d", &n, &m);
	arr = (int*)calloc(m + 1, sizeof(int));
	std::vector<int> coins;
	for (int i = 0; i < n; i++)
	{
		int coin = 0;
		fscanf(in, "%d", &coin);
		coins.push_back(coin);
	}
	std::sort(coins.begin(), coins.end());
	for (auto a = coins.begin(); a != coins.end(); a++)
	{
		for (int i = 1; i * *a <= m; i++)
		{
			arr[i * *a] = i;
		}
	}
	fprintf(out, "%d", arr[m]);
	fclose(in);
	fclose(out);
}