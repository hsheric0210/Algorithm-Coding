#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, N, M,A[10005],tcost;
struct C { int dist, unitcost; };
C CITY[10005], current;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (i = 0; i <= N; i++)cin >> A[i];
	for (i = 0; i < N; i++)
	{
		cin >> j;
		CITY[i] = { A[i], j };
	}
	CITY[N] = { A[N], 0x7FFFFFFF }; // last city
	
	while (1)
	{
		
	}
	cout << tcost;
	return 0;
}
