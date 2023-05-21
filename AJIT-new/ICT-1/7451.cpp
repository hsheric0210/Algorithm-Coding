// ICT-1 : RGB°Å¸®
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, p, q, r;
int DP[1005][3];
int main()
{
	cin >> n;
	DP[0][0] = DP[0][1] = DP[0][2] = 0;
	for (i = 0; i < n; i++)
	{
		cin >> p >> q >> r;
		DP[i+1][0] = min(DP[i][1], DP[i][2]) + p;
		DP[i+1][1] = min(DP[i][0], DP[i][2]) + q;
		DP[i+1][2] = min(DP[i][0], DP[i][1]) + r;
	}
	cout << *min_element(DP[n], DP[n] + 3) << '\n';
	return 0;
}