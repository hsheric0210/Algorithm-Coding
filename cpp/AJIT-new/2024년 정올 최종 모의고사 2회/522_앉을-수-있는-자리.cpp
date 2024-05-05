#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, N, A[100005];
int main()
{
	cin >> N; for (i = 0; i < N; i++)cin >> A[i];
	for (i = 0; i < N; i++)
	{
		if (A[i]) continue;
		if (i - 1 >= 0 && A[i-1]) continue;
		if (i + 1 < N && A[i+1]) continue;
		p++;
	}
	cout << p;
	return 0;
}
