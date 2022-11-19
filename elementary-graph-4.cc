/* 기초 알고리즘(그래프) - 4. 로봇미로찾기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <queue>

int arr[105];
int dist[105];
int navi[105];
int start = 0, end = 0;

int encodeCoord(int x, int y)
{
	return ((x & 0xffff) << 16) | (y & 0xffff);
}

int sumCoord(int x, int y)
{
	return y * 10 + x;
}

void decodeCoord(int encoded, int* x, int* y)
{
	*x = (encoded >> 16) & 0xffff;
	*y = (encoded & 0xffff);
}

bool validateAndAdd(std::queue<int>* q, std::set<int>* visited, int x, int y, int end, int distance, int fromDir)
{
	if (x < 0 || y < 0 || x >= 10 || y >= 10 || arr[sumCoord(x, y)] > 0)
		return;

	int enc = encodeCoord(x, y);
	if (visited->contains(enc))
		return;

	q->push(enc);
	visited->insert(enc);

	dist[sumCoord(x, y)] = distance;

	return enc == end;
}

void bfs(int start, int end)
{
	std::set<int> visited;
	std::queue<int> q;
	q.push(start);
	visited.insert(start);

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		int x = 0, y = 0;
		decodeCoord(top, &x, &y);
		int dst = dist[sumCoord(x, y)] + 1;

		if (validateAndAdd(&q, &visited, x + 1, y, end, dst, 1) || validateAndAdd(&q, &visited, x - 1, y, end, dst, 2) || validateAndAdd(&q, &visited, x, y + 1, end, dst, 3) || validateAndAdd(&q, &visited, x, y - 1, end, dst, 4))
			break;
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			fscanf(in, "%d ", arr + x * 10 + y);
	int sx = 0, sy = 0;
	fscanf(in, "%d %d ", &sx, &sy);
	dist[sumCoord(sx, sy)] = 1;
	start = encodeCoord(sx, sy);
	fscanf(in, "%d %d", &sx, &sy);
	end = encodeCoord(sx, sy);
	fclose(in);

	FILE* out = fopen("OUTPUT.TXT", "w");
	fclose(out);
	return 0;
}
