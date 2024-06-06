#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int i, j, k, l, a, b, c, F, V, A[105][105], D[105][105];
list<int>L;
int main()
{
	cin >> F >> V;
	for (i = 1; i <= F; i++)
		for (j = 1; j <= V; j++)
			cin >> A[i][j];
	for (i = 1; i <= F; i++)
		for (j = 1; j <= V; j++)
			if (j >= i)
				D[i][j] = max(D[i - 1][j - 1] + A[i][j], D[i][j - 1]);
	cout << D[F][V] << '\n';
#ifndef ONLINE_JUDGE
	for (i = 1; i <= F; i++)
	{
		for (j = 1; j <= V; j++)
			cout << D[i][j] << ' ';
		cout << '\n';
	}
#endif
	for (i = F, k = V; i >= 0; i--)
	{
		for (j = k - 1; j >= 0; j--)
		{
			if (D[i][k] > D[i][j])
			{
				L.push_back(k = j);
				break;
			}
		}
	}
	for (auto it = L.rbegin(); it != L.rend(); it++)
		cout << *it + 1 << "  ";
	return 0;
}
