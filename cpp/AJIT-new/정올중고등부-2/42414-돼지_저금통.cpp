#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int i, j, k, l, E, F, N;
PW T[1005];
struct PW { int p, w; };
int main()
{
	cin >> E >> F >> N;
	for (i = 0; i < N; i++)
	{
		cin >> j >> k;
		T[i] = { j,k };
	}



	return 0;
}
