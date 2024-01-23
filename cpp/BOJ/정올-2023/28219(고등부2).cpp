#include <iostream>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, vector<int>> edges;
unordered_set<int>visited,phasevisited;
deque<int>leafs;
int N, k, i, j, l, m, n, o, p, q, r, x, y, z;
void dfs(int edge, int depth, int maxdepth)
{
	// drop leaf from queue
	auto leaf = find(leafs.begin(), leafs.end(), edge);
	if (leaf != leafs.end())
		leafs.erase(leaf);

	// check visited
	if (visited.find(edge) != visited.end()) return;
	visited.insert(edge);
	phasevisited.insert(edge);
	//cout << "rec depth " << depth << " checking node " << edge << '\n';

	// recursion depth limit
	if (depth >= maxdepth) return;
	
	// recurse
	for (int e : edges[edge]) dfs(e, depth + 1, maxdepth);
}
int main()
{
	cin >> N >> k;

	// initialize adjacent list
	for (i = 0; i < N - 1; i++)
	{
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	p = 0;
	while (!edges.empty())
	{
		leafs.clear();
		// find leaf nodes
		for (auto r : edges)
			if (r.second.size() == 1)
				leafs.push_back(r.first);

		phasevisited.clear();
		// perform DFS's from each leaf node, efficiently removing other intercepting leaf nodes.
		while (!leafs.empty())
		{
			//cout << "start dfs from " << leafs.front() << '\n';
			visited.clear();
			dfs(leafs.front(), 0, k * 2);
			p++;
		}

		// drop all processed nodes from adjacent list (not so efficient)
		unordered_map<int, vector<int>> newEdges;
		for (auto& edge : edges)
		{
			if (phasevisited.find(edge.first) != phasevisited.end()) continue;

			vector<int>adjList;
			for (auto adj : edge.second)
			{
				if (phasevisited.find(adj) != phasevisited.end()) continue;
				adjList.push_back(adj);
			}
			newEdges[edge.first] = adjList;
		}
		edges = newEdges;
	}
	cout << p << '\n';
	return 0;
}