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
int i, j, k, l, m, n, F, V, A[105][105], D[105][105];
list<int>L;
int main() // ²ÉÁø¿­
{
	cin >> F >> V;
	for (i = 1; i <= F; i++) for (j = 1; j <= V; j++) cin >> A[i][j];
	for (i = 1; i <= F; i++) for (j = 1; j <= V; j++) if (i <= j) D[i][j] = max(D[i - 1][j - 1] + A[i][j], D[i][j - 1]);
	cout << D[F][V] << '\n';
	for (i = F, k = V; i > 0; i--)
		for (j = k; j > 0; j--)
		{
			if (D[i][j - 1] < D[i][j])
			{
				L.push_back(j);
				k = j - 1;
				break;
			}
		}
	for (auto it = L.rbegin(); it != L.rend(); it++)
		cout << *it << "  ";
	return 0;
}
// 7ºÐ 20ÃÊ 86
