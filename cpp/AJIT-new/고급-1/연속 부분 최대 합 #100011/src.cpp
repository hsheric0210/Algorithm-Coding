#include <iostream>
#include <algorithm>
using namespace std;
int N, i, j, k, l, m, n, p, q, r, A[105], D[105], M[105];
int main()
{
	cin >> N;
	for (i = 1; i <= N; i++) cin >> A[i];
	for (i = 1; i <= N; i++)
	{
		if (D[i - 1] + A[i] < A[i])
		{
			D[i] = A[i];

			// put the marker at the point of change
			M[i] = 1;
		}
		else
			D[i] = D[i - 1] + A[i];
	}

	// find the index of max dp element
	j = max_element(D + 1, D + N + 1) - D;

	// find the last marker; if not found, default to 1 (begin of the sequence)
	for (k = 1, i = j - 1; i > 0; i--)
		if (M[i])
		{
			k = i;
			break;
		}
	cout << k << ' ' << j << ' ' << D[j];
	return 0;
}