/*
효율적인 해킹
https://www.acmicpc.net/problem/1325
BFS+DP
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
int m, n;
map<int, set<int>> theMap;
typedef struct _entry {
	int id;
	int depth;
} entry;
map<int, entry> depthCache;
entry dfs(int parent)
{
	deque<entry> q;
	q.push_back({ parent, 1 });
	entry maxDepth = { parent, 1 };
	while (!q.empty())
	{
		entry front = q.front();
		q.pop_front();
		if (theMap.find(front.id) != theMap.end())
		{
			set<int> linked = theMap[front.id];
			for (auto a = linked.begin(); a != linked.end(); a++)
			{
				int newDepth;
				if (depthCache.find(*a) != depthCache.end())
				{
					newDepth = depthCache[*a].depth;
					q.push_back({ *a, });
				}
				else
				{
					newDepth = front.depth + 1;
					q.push_back({ *a, newDepth });
				}
				if (newDepth > maxDepth.depth)
					maxDepth = { *a, newDepth };
			}
		}
	}
	return maxDepth;
}
int depthCmp(pair<int, entry> a, pair<int, entry> b)
{
	return a.second.depth < b.second.depth;
}
int idCmp(entry a, entry b)
{
	return a.id > b.id;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (theMap.find(b) == theMap.end())
		{
			set<int> tmp;
			theMap[b] = tmp;
		}
		theMap[b].insert(a);
	}

	// using dfs to find 'maximum depth'
	for (int i = 0; i < n; i++)
	{
		depthCache[i] = dfs(i + 1);
	}

	int maxDepth = max_element(depthCache.begin(), depthCache.end(), depthCmp)->second.depth;
	vector<int> filteredEntries;
	for (int i = 0; i < n; i++)
		if (depthCache[i].depth == maxDepth)
			filteredEntries.push_back(depthCache[i].id);
	sort(filteredEntries.begin(), filteredEntries.end());
	for (auto a = filteredEntries.begin(); a != filteredEntries.end(); a++)
		cout << *a << ' ' << endl;
	cout << endl;
}