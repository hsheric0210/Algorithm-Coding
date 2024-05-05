#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<iomanip>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, N, M[105][105], D[105][105], V[105][105];
struct P { int i, j, k; };
int main()
{
	cin >> N; for (i = 1; i <= N; i++)for (j = 1; j <= N; j++)cin >> M[i][j];
	//bfs-dp from (N, N) to (1, 1)
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			D[i][j] = M[i][j] + max(D[i - 1][j], D[i][j - 1]);

	cout << D[N][N] << '\n';

	//bt
	deque<P>bt;
	vector<char>trace;
	bt.push_back({ N,N,0 });
	while (!bt.empty())
	{
		P t = bt.front();
		bt.pop_front();
		i = t.i, j = t.j;
		if (t.k > 0)
			trace.push_back(t.k == 1 ? 'R' : 'D');

		// 1 = only left avail
		// 2 = only up avail
		// 3 = both avail
		k = ((i > 1 && !V[i - 1][j]) << 1) | (j > 1 && !V[i][j - 1]);
		switch (k)
		{
		case 1:
			bt.push_back({ i,j - 1, 1 });
			break;
		case 2:
			bt.push_back({ i - 1,j, 2 });
			break;
		case 3:
			if (D[i - 1][j] <= D[i][j - 1])
				bt.push_back({ i,j - 1, 1 });
			else
				bt.push_back({ i - 1,j, 2 });
		}
	}
	while (!trace.empty())
	{
		cout << trace.back() << '\n';
		trace.pop_back();
	}
	return 0;
}
