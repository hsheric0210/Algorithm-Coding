#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n; // read size
	int** dp = new int* [n]; for (int i = 0; i < n; i++) dp[i] = new int[n] { 0 }; // alloc dp
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			cin >> dp[i][j];
			if (i > 0) // prevent overflow
			{
				if (j == 0) // first segment
					dp[i][0] += dp[i - 1][0]; // select right
				else if (j == i) // last segment
					dp[i][i] += dp[i - 1][j - 1]; // select left
				else // middle segment
					dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]); // select bigger one
			}
		}
	cout << *max_element(dp[n - 1], dp[n - 1] + n);
	return 0;
}