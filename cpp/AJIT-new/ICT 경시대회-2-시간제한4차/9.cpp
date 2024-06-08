#include<iostream>
#include<iomanip>
#include<algorithm>
#include<utility>
#include<numeric>
#include<memory>
#include<vector>
#include<list>
#include<deque>
#include<bitset>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
char pattern[100], input[100][100];
int i, j, k, l, N, p, q;
bool D[100][100];
list<int>L;
int main() // 만능 카드
{
	cin.getline(pattern, 100);
	p = strlen(pattern);
	cin >> N;
	cin.getline(input[0], 100); // eat empty lines;
	for (i = 0; i < N; i++)
	{
		cin.getline(input[i], 100);
		q = strlen(input[i]);

		memset(D, 0, 100 * 100 * sizeof(bool));
		D[0][0] = 1;
		for (j = 0; j < p; j++)
			if (pattern[j] == '*')
				D[j+1][0] = D[j][0];
		for (j = 0; j < p; j++)
			for (k = 0; k < q; k++)
			{
				if (pattern[j] == '*')
					D[j + 1][k + 1] = D[j + 1][k] || D[j][k + 1] || D[j][k];
				else if (pattern[j] == '?' || pattern[j] == input[i][k])
					D[j + 1][k + 1] = D[j][k];
			}

		if (D[p][q])
			L.push_back(i);
	}
	cout << L.size() << '\n';
	for (int v : L)
		cout << input[v] << '\n';
	return 0;
}
// 9분 52초 34
