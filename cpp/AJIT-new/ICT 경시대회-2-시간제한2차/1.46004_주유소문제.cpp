#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, N, M, ds[10005], cci; // ds:distance-sum cci:current-city-index
struct P { int dist, cost; };
P C[10005]; // C:City
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) { cin >> j; ds[i] = (i > 0 ? ds[i - 1] : 0) + j; }
	for (i = 0; i <= N; i++) { cin >> j; C[i] = { ds[i] - ds[i - 1], j }; }
	CC = c
	return 0;
}
