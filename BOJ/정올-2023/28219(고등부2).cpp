#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, vector<int>> edges;
int visited[200005];
int N, k, i, j, k, l, m, n, o, p, q, r, x, y, z, gcount;
int dfs(int edge, int depth, int prevTrigDepth)
{
	if (visited[edge]) return visited[edge]; // optimiz.
	for (int e : edges[edge])
		dfs(e, depth+1, prevTrigDepth);
}
int main()
{
	cin >> N >> k;
	// initialize adjacent list
	for (i = 0; i < N; i++)
	{
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	// find leaf node
	int leaf = -1;
	for (auto r : edges)
	{
		if (r.second.size() == 1)
		{
			leaf = r.first;
			break;
		}
	}

	if (leaf == -1)
	{
		cout << "no leaf node\n";
		return 0xDEADBEEF;
	}

	// do the recursive dfs
	dfs(leaf, 0, 0);

	// count the groups
	return gcount;
}