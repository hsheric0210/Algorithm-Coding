/* 기초 알고리즘(그래프) - 4. 로봇미로찾기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
#include <set>
#include <optional>

int arr[105];
int parent[105];
int distance[105];

int pack(int x, int y)
{
	return y * 10 + x;
}

typedef struct _coord {
	int x;
	int y;

	int packIt()
	{
		return pack(x, y);
	}

	bool eq(struct _coord other)
	{
		return x == other.x && y == other.y;
	}

	bool valid()
	{
		return x >= 0 && x < 10 && y >= 0 && y < 10;
	}
} coord;

coord unpack(int packed)
{
	return { packed % 10, packed / 10 };
}

coord parentOf(coord child)
{
	return unpack(parent[pack(child.x, child.y)]);
}

std::deque<coord> backtrack(coord node, coord start, coord end)
{
	std::deque<coord> dq;
	dq.push_front(end);
	while (!dq.front().eq(start))
	{
		dq.push_front(parentOf(dq.front()));
	}
	return dq;
}

int validateAndAdd(std::queue<int>* q, std::set<int>* visited, coord par, int offsetx, int offsety, int end, int dist)
{
	coord updated = { par.x + offsetx, par.y + offsety };
	int enc = updated.packIt();
	if (!updated.valid())
		return -1;

	if (arr[enc] > 0)
	{
		printf("met obstacle @ (%d, %d)\n", updated.x, updated.y);
		return -1;
	}

	if (visited->contains(enc))
		return -1;

	q->push(enc);
	visited->insert(enc);
	parent[enc] = par.packIt();
	distance[enc] = dist;

	if (enc == end)
		return enc;
	return -1;
}

std::optional<std::deque<coord>> bfs(int start, int end)
{
	std::set<int> visited;
	std::queue<int> q;
	q.push(start);
	visited.insert(start);

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		coord c = unpack(top);
		int dst = distance[top] + 1;

		int adj[4] = { 0 };
		adj[0] = validateAndAdd(&q, &visited, c, 1, 0, end, dst);
		adj[2] = validateAndAdd(&q, &visited, c, 0, 1, end, dst);
		adj[1] = validateAndAdd(&q, &visited, c, -1, 0, end, dst);
		adj[3] = validateAndAdd(&q, &visited, c, 0, -1, end, dst);

		for (int i = 0; i < 4; i++)
			if (adj[i] != -1)
			{
				return backtrack(unpack(adj[i]), unpack(start), unpack(end));
			}
	}
	return std::nullopt;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			fscanf(in, "%d ", arr + pack(x, y));
	int sx = 0, sy = 0;
	fscanf(in, "%d %d ", &sx, &sy);
	sx--; sy--;
	distance[pack(sx, sy)] = 1;
	int start = pack(sx, sy);
	fscanf(in, "%d %d", &sx, &sy);
	sx--; sy--;
	int end = pack(sx, sy);
	fclose(in);
	std::optional<std::deque<coord>> _dq = bfs(start, end);
	if (!_dq.has_value())
		return 1;
	std::deque<coord> dq = _dq.value();
	FILE* out = fopen("OUTPUT.TXT", "w");
	fprintf(out, "%d\n", distance[pack(sx, sy)]);
	for (auto a = dq.begin(); a != dq.end(); a++)
	{
		fprintf(out, "%d %d\n", a->x + 1, a->y + 1);
	}
	fclose(out);
	return 0;
}
