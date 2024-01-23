#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, m, n, o, p, q, r;
typedef struct _a
{
	int x1, y1, x2, y2, depth;
	int operator==(struct _a a)
	{
		return x1 == a.x1 && x2 == a.x2 && y1 == a.y1 && y2 == a.y2;
	}
} a;
typedef struct _b
{
	int x, y;
} b;
vector<a> ar;
vector<a> visited;
deque<a> bfs;
b dest;
void drop_contained()
{
	vector<a> deathnote;
	for (auto a = ar.begin(); a != ar.end(); a++)
	{
		if (a->y1 == a->y2)
		{
			for (auto b = ar.begin(); b != ar.end(); b++)
			{
				if (b == a)continue;
				if (b->y1 == b->y2 && b->y2 == a->y2 && b->x1 <= a->x1 && b->x2 >= a->x2) // contained
				{
					//cout << "drop " << a->x1 << ' ' << a->y1 << ' ' << a->x2 << ' ' << a->y2 << " because it's contained by " << b->x1 << ' ' << b->y1 << ' ' << b->x2 << ' ' << b->y2 << '\n';
					deathnote.push_back(*a);
					break;
				}
			}
		}
		else if (a->x1 == a->x2)
		{
			for (auto b = ar.begin(); b != ar.end(); b++)
			{
				if (b == a)continue;
				if (b->x1 == b->x2 && b->x2 == a->x2 && b->y1 <= a->y1 && b->y2 >= a->y2) // contained
				{
					//cout << "drop " << a->x1 << ' ' << a->y1 << ' ' << a->x2 << ' ' << a->y2 << " because it's contained by " << b->x1 << ' ' << b->y1 << ' ' << b->x2 << ' ' << b->y2 << '\n';
					deathnote.push_back(*a);
					break;
				}
			}
		}
	}
	vector<a>cpy;
	for (auto a = ar.begin(); a != ar.end(); a++)
		if (find(deathnote.begin(), deathnote.end(), *a) == deathnote.end())
			cpy.push_back(*a);
	ar = cpy;
}
bool push_adj(a& t)
{
	if (t.x1 == t.x2 && t.x2 == dest.x && t.y1 <= dest.y && dest.y <= t.y2) // Exact X, In-range Y
		return true;
	if (t.y1 == t.y2 && t.y2 == dest.y && t.x1 <= dest.x && dest.x <= t.x2) // Exact Y, In-range X
		return true;

	if (t.y1 == t.y2)
	{
		for (i = t.x1; i <= t.x2; i++)
		{
			for (auto a = ar.begin(); a != ar.end(); a++)
			{
				if (*a == t)
					continue;
				if (a->y1 <= t.y1 && t.y1 <= a->y2 && a->x1 <= i && i <= a->x2 && find(visited.begin(), visited.end(), *a) == visited.end())
				{
					bfs.push_back({a->x1, a->y1, a->x2, a->y2, t.depth + 1});
					cout << "SameY push " << a->x1 << ' ' << a->y1 << ' ' << a->x2 << ' ' << a->y2 << " with depth " << (t.depth+1) << '\n';
					visited.push_back(*a);
				}
			}
		}
	}
	
	if (t.x1 == t.x2)
	{
		for (i = t.y1; i <= t.y2; i++)
		{
			for (auto a = ar.begin(); a != ar.end(); a++)
			{
				if (*a == t)
					continue;
				if (a->x1 <= t.x1 && t.x1 <= a->x2 && a->y1 <= i && i <= a->y2 && find(visited.begin(), visited.end(), *a) == visited.end())
				{
					bfs.push_back({ a->x1, a->y1, a->x2, a->y2, t.depth + 1 });
					cout << "SameX push " << a->x1 << ' ' << a->y1 << ' ' << a->x2 << ' ' << a->y2 << " with depth " << (t.depth+1) << '\n';
					visited.push_back(*a);
				}
			}
		}
	}
	return false;
}
int main()
{
	cin >> p >> q >> k;
	for (i = 0; i < k; i++)
	{
		cin >> r >> j >> l >> m >> n;
		ar.push_back({ min(j, m) , min(l, n), max(j, m), max(l, n) });
	}

	drop_contained();

	cin >> i >> j >> k >> l;
	bfs.push_back({ i, j, i, j });
	dest = { k,l };
	int depth = 0;
	while (!bfs.empty())
	{
		auto& top = bfs.front();
		bfs.pop_front();
		cout << "top is " << top.x1 << ' ' << top.y1 << ' ' << top.x2 << ' ' << top.y2 << '\n';
		if (push_adj(top))
		{
			depth = top.depth;
			break;
		}
	}

	cout << (depth) << '\n';
}