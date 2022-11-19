/* 기초 알고리즘(그래프) - 2. 나는중국집사장 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

int n, r;
int* edges;
std::set<int> visited;

std::vector<int> adjNodes(int node)
{
	std::vector<int> avail;
	for (int i = 0; i < r; i++)
	{
		int e = edges[i];
		if ((e & 0xffff) == node)
		{
			avail.push_back((e >> 16) & 0xffff);
		}
		else if (((e >> 16) & 0xffff) == node)
		{
			avail.push_back(e & 0xffff);
		}
	}

	return avail;
}

int bfs(int start, int target)
{
	int depth = 0;
	visited.clear();

	std::queue<int> q;
	q.push(start);
	visited.insert(start);

	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		visited.insert(top);

		std::vector<int> avail = adjNodes(top);

		depth++;
		for (auto a = avail.begin(); a != avail.end(); a++)
		{
			if (!visited.contains(*a))
			{
				q.push(*a);
				visited.insert(*a);
				if (*a == target)
				{
					return depth + 1;
				}
			}
		}
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	// dummy input - 1
	int dummy = 0;
	fscanf(in, "%d", &dummy);

	n = 0, r = 0;
	fscanf(in, "%d %d", &n, &r);

	// pack two WORDs into DWORD
	edges = (int*)malloc(r * sizeof(int));
	for (int i = 0; i < r; i++)
	{
		int first = 0, second = 0;
		fscanf(in, "%d %d", &first, &second);
		edges[i] = ((first & 0xffff) << 16) | (second & 0xffff);
	}

	fclose(in);

	FILE* out = fopen("OUTPUT.TXT", "w");
	int sum = 0;
	for (int i = 2; i <= n; i++)
	{
		int delta = bfs(1, i);
		printf("bfs[%d]=%d\n", i, delta);
		sum += delta;
	}
	fprintf(out, "%d", sum);
	fclose(out);
	return 0;
}
