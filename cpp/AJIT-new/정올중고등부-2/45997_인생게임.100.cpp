#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int i, j, k, l, N, A[100005], D[100005];
int main()
{
	cin >> N; for (i = 1; i <= N; i++)cin >> A[i];
	for (i = 1; i <= N + 1; i++)
	{
		for (j = max(0, i - 6); j <= i; j++)
		{
			if (D[i] == 0)D[i] = 0x7FFFFFFF;
			D[i] = min(D[i], D[j] + A[i]);
		}
	}
	cout << D[N + 1];
	return 0;
}
