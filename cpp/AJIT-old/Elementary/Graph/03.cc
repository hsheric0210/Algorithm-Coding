/* 기초 알고리즘(그래프) - 3. 숫자등고선 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

int* arr;
int n;

typedef struct _coord
{
	int x;
	int y;
	int depth;
} coord;

coord decode(int encoded)
{
	coord cd = { 0 };
	cd.depth = (encoded >> 24) & 0xff;
	cd.x = (encoded >> 12) & 0xff;
	cd.y = encoded & 0xff;
	return cd;
}

int encode(int x, int y, int depth)
{
	return ((depth & 0xff) << 24) | ((x & 0xff) << 12) | (y & 0xff);
}

int encodeCoord(int x, int y)
{
	return ((x & 0xff) << 16) | (y & 0xff);
}

void validate_and_push(std::queue<int>* q, std::set<int>* visited, int x, int y, int depth)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return;

	int encoded = encode(x, y, depth);
	int coord = encodeCoord(x, y);

	// already visited
	if (visited->contains(coord))
		return;
	//printf("coord[%d][%d]=%d\n", x, y, depth);
	q->push(encoded);
	visited->insert(coord);
	arr[x + y * n] = depth;
}

void bfs(int startx, int starty)
{
	std::set<int> visited;
	std::queue<int> q;
	int startcoord = encode(startx, starty, 1);
	q.push(startcoord);
	arr[(startx)+(starty)*n] = 1;
	visited.insert(encodeCoord(startx, starty));

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		coord dec = decode(top);

		validate_and_push(&q, &visited, dec.x + 1, dec.y, dec.depth + 1);
		validate_and_push(&q, &visited, dec.x - 1, dec.y, dec.depth + 1);
		validate_and_push(&q, &visited, dec.x, dec.y + 1, dec.depth + 1);
		validate_and_push(&q, &visited, dec.x, dec.y - 1, dec.depth + 1);
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	n = 0;
	int sx = 0, sy = 0;
	fscanf(in, "%d", &n);
	fscanf(in, "%d %d", &sx, &sy);
	fclose(in);

	arr = (int*)malloc(sizeof(int) * n * n);
	bfs(sx - 1, sy - 1);

	FILE* out = fopen("OUTPUT.TXT", "w");
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(out, "%2d ", arr[i * n + j]);
		}
		fprintf(out, "\n");
	}
	fclose(out);
	return 0;
}
