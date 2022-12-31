/* 기초 알고리즘(그래프) - 4. 로봇미로찾기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <optional>

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

int validateAndAdd(std::queue<int>* q, std::set<int>* visited, int px, int py, int x, int y, int end, int distance)
{
	if (x < 0 || y < 0 || x >= 10 || y >= 10 || arr[sumCoord(x, y)] > 0)
		return -1;

	int enc = encodeCoord(x, y);
	if (visited->contains(enc))
		return -1;

	q->push(enc);
	visited->insert(enc);
	navi[sumCoord(x, y)] = sumCoord(px, py);

	dist[sumCoord(x, y)] = distance;

	if (enc == end)
		return enc;
	return -1;
}

std::vector<int> backtrack(int node, int start, int end)
{
	std::vector<int> v;
	v.push_back(end);
	while (v.back() != start)
	{
		int x = 0, y = 0;
		decodeCoord(v.back(), &x, &y);
		v.push_back(navi[sumCoord(x, y)]);
	}
	std::reverse(v.begin(), v.end());
	return v;
}

std::vector<int> *bfs(int start, int end)
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

		int adj[4] = { 0 };
		adj[0] = validateAndAdd(&q, &visited, x, y, x + 1, y, end, dst);
		adj[1] = validateAndAdd(&q, &visited, x, y, x - 1, y, end, dst);
		adj[2] = validateAndAdd(&q, &visited, x, y, x, y + 1, end, dst);
		adj[3] = validateAndAdd(&q, &visited, x, y, x, y - 1, end, dst);

		for (int i = 0; i < 4; i++)
			if (adj[i] != -1)
			{
				std::vector<int> v = backtrack(adj[i], start, end);
				return &v;
			}
	}
	return NULL;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			fscanf(in, "%d ", arr + pack(x,y));
	int sx = 0, sy = 0;
	fscanf(in, "%d %d ", &sx, &sy);
	dist[sumCoord(sx, sy)] = 1;
	start = encodeCoord(sx, sy);
	fscanf(in, "%d %d", &sx, &sy);
	end = encodeCoord(sx, sy);
	fclose(in);
	std::vector<int> *dq = bfs(start, end);
	if (dq == NULL) return 1;
	FILE* out = fopen("OUTPUT.TXT", "w");
	fprintf(out, "%d\n", dist[sumCoord(sx, sy)]);
	for (auto a = dq->begin(); a != dq->end(); a++)
	{
		int x = 0, y = 0;
		decodeCoord(*a, &x, &y);
		fprintf(out, "%d %d", x, y);
	}
	fclose(out);
	return 0;
}
