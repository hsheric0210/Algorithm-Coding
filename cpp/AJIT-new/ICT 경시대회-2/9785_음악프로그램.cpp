#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;
int i, j, k, l, N, M, K;
struct E { vector<int>ADJ; int incoming = -1; };
E EDGE[1005];
vector<int>TMP;
set<int>NEXT;
unordered_set<int>VISITED;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (i = 1; i <= M; i++)
	{
		cin >> K; l = 0;
		while (K--)
		{
			// l = previous node
			cin >> k;
			EDGE[k].incoming++;
			if (l != 0) EDGE[l].ADJ.push_back(k);
			l = k;
		}
	}
	while (1)
	{
		for (i = 1; i <= N; i++)if (!EDGE[i].incoming)EDGE[i].incoming = -1;
		EDGE
	}
	return 0;
}
