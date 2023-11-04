/* 기초 알고리즘(그래프) - 1. 깊이우선탐색과 너비우선탐색 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>

#define INDEXOF(ch) ((ch) - 'A')
#define CHAROF(idx) ((idx) + 'A')

int n = 0, e = 0;
int* edges;
std::set<int> visited;

std::vector<int> getAdjacentNodes(int currentnode)
{
	std::vector<int> found;

	for (int i = 0; i < e; i++)
	{
		if (((edges[i] >> 16) & 0xffff) == currentnode) // MSB == current
			found.push_back(edges[i] & 0xffff);

		if ((edges[i] & 0xffff) == currentnode) // LSB == current
			found.push_back((edges[i] >> 16) & 0xffff);
	}

	// Distinct
	found.erase(std::unique(found.begin(), found.end()), found.end());

	// Sort
	std::sort(found.begin(), found.end());
	return found;
}

void dfs(FILE* f, int currentnode)
{
	// already-visited node
	if (visited.find(currentnode) != visited.end())
		return;

	visited.insert(currentnode);
	fprintf(f, "%c", CHAROF(currentnode));

	std::vector<int> avail = getAdjacentNodes(currentnode);
	for (auto a = avail.begin(); a != avail.end(); a++)
		dfs(f, *a);
}

void bfs(FILE* f, int currentnode)
{
	std::deque<int> nodes;
	nodes.push_back(currentnode);
	visited.insert(currentnode);

	while (!nodes.empty())
	{
		int v = nodes.front();
		nodes.pop_front();

		fprintf(f, "%c", CHAROF(v));

		std::vector<int> avail = getAdjacentNodes(v);
		for (auto a = avail.begin(); a != avail.end(); a++)
			if (visited.find(*a) == visited.end())
			{
				nodes.push_back(*a);
				visited.insert(*a);
			}
	}
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	n = 0, e = 0;
	fscanf(in, "%d %d", &n, &e);

	// pack two WORDs into DWORD
	edges = (int*)malloc(e * sizeof(int));
	for (int i = 0; i < e; i++)
	{
		char first = 0, second = 0;
		fscanf(in, " %c %c", &first, &second);
		edges[i] = ((INDEXOF(first) & 0xffff) << 16) | (INDEXOF(second) & 0xffff);
	}

	char start = 0;
	fscanf(in, " %c", &start);

	fclose(in);

	FILE* out = fopen("OUTPUT.TXT", "w");
	dfs(out, INDEXOF(start));
	fprintf(out, "\n");
	visited.clear();
	bfs(out, INDEXOF(start));
	fprintf(out, "\n");
	fclose(out);
	return 0;
}
