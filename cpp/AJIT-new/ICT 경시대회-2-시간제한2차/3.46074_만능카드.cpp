#include<iostream>
#include<algorithm>
#include<cstring>
#include<list>
using namespace std;
int i, j, k, l, N, p, q;
bool DP[55][55];
char input[55][55];
char pattern[55];
list<int>OK;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin.getline(pattern, 55);
	p = strlen(pattern);
	cin >> N;
	cin.getline(input[0], 55); // eat up the leading '\n' char
	for (i = 0; i < N; i++)
	{
		cin.getline(input[i], 55);
		q = strlen(input[i]);

		// init
		memset(DP, 0, 55 * 55 * sizeof(bool));
		DP[0][0] = 1;
		for (j = 0; j < p; j++) if (pattern[j] == '*') DP[0][j + 1] = DP[0][j];

		// dp
		for (j = 0; j < q; j++)
			for (k = 0; k < p; k++)
				if (pattern[k] == '*')
					DP[j + 1][k + 1] = DP[j][k + 1] || DP[j + 1][k] || DP[j][k];
				else if (pattern[k] == '?' || pattern[k] == input[i][j])
					DP[j + 1][k + 1] = DP[j][k];

		if (DP[q][p])
			OK.push_back(i);
	}

	cout << OK.size() << '\n';
	for (int ok : OK)
		cout << input[ok] << '\n';
	return 0;
}
// 결과: 8분 50초
