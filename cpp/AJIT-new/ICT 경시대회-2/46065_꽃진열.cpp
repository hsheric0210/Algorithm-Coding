#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, F, V, T[105][105];
vector<int>HIST;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> F >> V;
	for (i = 1; i <= F; i++)
		for (j = 1; j <= V; j++)
		{
			cin >> k;
			if (i > j)continue;//skip
			T[i][j] = max(T[i][j - 1], T[i - 1][j - 1] + k);
		}
	cout << T[F][V] << '\n';
	//bt
	for (i = F, j = V + 1; i > 0; i--)
	{
		j = max_element(T[i] + 1, T[i] + j) - T[i];
		HIST.push_back(j);
	}
	for (auto it = HIST.rbegin(); it != HIST.rend(); it++)
		cout << *it << "  ";
	return 0;
}
