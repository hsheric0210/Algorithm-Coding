#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int i, j, k, l, N, D[1005][1005];
char A[1005], B[1005];
struct P { int p, q; };
int main()
{
	cin.getline(A, 1002);
	cin.getline(B, 1002);
	for (i = 0; A[i]; i++) for (j = 0; B[j]; j++) D[i + 1][j + 1] = (A[i] == B[j]) ? D[i][j] + 1 : max(D[i + 1][j], D[i][j + 1]);
	if (D[i][j] == 0)
	{
		cout << "-1\nNo";
		return 0;
	}

	cout << D[i][j] << '\n';

	//bfs
	queue<P>d; vector<char>ch;
	d.push({ i, j });
	while (!d.empty())
	{
		P t = d.front();
		d.pop();
		if (t.p == 0 || t.q == 0) continue;
		if (A[t.p - 1] == B[t.q - 1])
		{
			d.push({ t.p - 1, t.q - 1 });
			ch.push_back(A[t.p - 1]);
			continue;
		}

		if (D[t.p - 1][t.q] > D[t.p][t.q - 1])
			d.push({ t.p - 1, t.q });
		else
			d.push({ t.p, t.q - 1 });
	}
	while (!ch.empty())
	{
		cout << ch.back();
		ch.pop_back();
	}

	return 0;
}
