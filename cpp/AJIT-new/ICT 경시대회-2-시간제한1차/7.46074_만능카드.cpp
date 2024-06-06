#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
char pattern[55];
int i, j, k, l, N, p, q, r, a, b, c;
bool L[55][55];
char input[25][55];
vector<int>V;
int main()
{
	cin.getline(pattern, 55);
	cin >> N;
	q = strlen(pattern);
	for (i = 0; i <= N; i++)
	{
		cin.getline(input[i], 55);

		memset(L, 0, 55 * 55 * sizeof(bool));
		L[0][0] = 1;
		for (b = 0; b < q; b++) // handle empty input + nonempty pattern (filled with '*'s)
			if (pattern[b] == '*')
				L[0][b + 1] = L[0][b];

		for (a = 0, p = strlen(input[i]); a < p; a++)
		{
			for (b = 0; b < q; b++)
			{
				if (pattern[b] == '*')
					L[a + 1][b + 1] = L[a][b + 1] || L[a + 1][b];
				else if (pattern[b] == input[i][a] || pattern[b] == '?')
					L[a + 1][b + 1] = L[a][b];
			}
		}

		if (L[p][q])
			V.push_back(i);
	}

	cout << V.size() << '\n';
	for (int v : V) cout << input[v] << '\n';
	return 0;
}
