/*
효율적인 해킹
https://www.acmicpc.net/problem/1325
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
entry dfs(int parent)
{
	deque<entry> q;
	q.push_front({ parent, 1 });
	int maxDepth = 1;
	while (!q.empty())
	{
		entry front = q.front();
		q.pop_front();
		if (theMap.find(front.id) != theMap.end())
		{
			set<int> linked = theMap[front.id];
			for (auto a = linked.begin(); a != linked.end(); a++)
			{
				int newDepth = front.depth + 1;
				q.push_front({ *a, newDepth });
				if (newDepth > maxDepth)
					maxDepth = newDepth;
			}
		}
	}
	return { parent, maxDepth };
}
int depthCmp(entry a, entry b)
{
	return a.depth < b.depth;
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
	entry* entries = new entry[n]{ 0 };
	for (int i = 0; i < n; i++)
		entries[i] = dfs(i + 1);

	int maxDepth = max_element(entries, entries + n, depthCmp)->depth;
	vector<int> filteredEntries;
	for (int i = 0; i < n; i++)
		if (entries[i].depth == maxDepth)
			filteredEntries.push_back(entries[i].id);
	sort(filteredEntries.begin(), filteredEntries.end());
	for (auto a = filteredEntries.begin(); a != filteredEntries.end(); a++)
		cout << *a << ' ' << endl;
	cout << endl;
}