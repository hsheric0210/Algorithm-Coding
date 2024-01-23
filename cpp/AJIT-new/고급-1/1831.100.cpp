/*
문제명: DFS와 BFS
교실: 고급-1
난이도: Mid
알고리즘: DFS, BFS
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <deque>
#include <unordered_map>
#include <cstring>
#include <set>
using namespace std;

// vector<vector<int>>하니까 subscript OOB 오류...
// 방문할 수 있는 정점이 여러 개라면 숫자가 작은 것부터 -> 정렬 -> binary tree set
unordered_map<int, set<int>>adjList;
deque<int>bfs;
int N, M, V, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, visited[10005];
void dfs(int node)
{
	cout << node << ' ';
	visited[node] = 1;
	for (int adj : adjList[node])
		if (!visited[adj])
			dfs(adj);
}
int main()
{
	cin >> N >> M >> V;
	for (i = 0; i < M; i++)
	{
		cin >> x >> y;
		adjList[x].insert(y);
		adjList[y].insert(x);
	}

	dfs(V);
	cout << '\n';
	memset(visited, 0, 10005 * sizeof(int)); // clear visited

	bfs.push_back(V);
	visited[V] = 1;
	while (!bfs.empty())
	{
		int node = bfs.front();
		bfs.pop_front();
		cout << node << ' ';
		for (int adj : adjList[node])
		{
			if (!visited[adj])
			{
				bfs.push_back(adj);
				visited[adj] = 1;
			}
		}
	}
	cout << '\n';
	return 0;
}