/* 기초 알고리즘(다이나믹) - 3. 헨델과그레텔 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <optional>
#include <vector>
#include <algorithm>
#include <deque>

int* arr;
int n, m, k;

typedef struct _coord {
	int x;
	int y;
} coord;

typedef struct _node {
	coord c;
	int sum;
} node;

int to_index(coord c)
{
	return c.x + c.y * n;
}

int max;

bool fixcoord(coord* c)
{
	if (c->y < 0)
		c->y += m;
	else if (c->y >= m)
		c->y -= m;

	return c->x >= 0 && c->x < n;
}

int* sum;

int main(int argc, char** argv) {
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	fscanf(in, "%d %d %d", &m, &n, &k);
	arr = (int*)calloc(m * n, sizeof(int));
	sum = (int*)calloc(m * n, sizeof(int));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(in, "%d", arr + to_index({ j, i }));
		}
	}
	sum[0] = arr[0];
	for (int y = 0; y < m; y++)
	{
		for (int x = 1; x < k; x++)
		{
			coord currentBlock = { x, y };
			std::vector<int> q;

			// push three left candidates
			for (int yoff = -1; yoff <= 1; yoff++)
			{
				coord backingBlock = { x - 1, y + yoff };
				if (fixcoord(&backingBlock)) // will prevent negative x and handle rolling y
				{
					int local_sum = sum[to_index(backingBlock)];
					if (local_sum != 0)
						q.push_back(local_sum);
				}
			}

			// find the max between three candidates
			auto imax = std::max_element(q.begin(), q.end());

			// set it as my sum
			if (imax != q.end())
				sum[to_index(currentBlock)] = *imax + arr[to_index(currentBlock)];
		}
	}
	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%d ", sum[to_index({ x, y })]);
		}
		printf("\n");
	}
	int max = *std::max_element(sum, sum + m * n);
	fprintf(out, "%d", max);
	fclose(in);
	fclose(out);
}