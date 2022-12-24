#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
int n;
int ne;
vector<int>* e;
int* visited;
int find()
{
	deque<int> dq;
	dq.push_back(1);
	int depth = -2;
	while (!dq.empty())
	{
		int h = dq.front();
		dq.pop_front();
		for (auto i = e[h].begin(); i != e[h].end(); i++)
			if (!visited[*i])
			{
				dq.push_back(*i);
				visited[*i] = 1;
			}
		depth++;
	}
	return depth;
}
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> ne;
	e = new vector<int>[n + 1]{};
	visited = new int[n + 1]{ 0 };
	for (int i = 0; i < ne; i++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	cout << find() << endl;
	return 0;
}