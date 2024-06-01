#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, N, C[1005];
struct P { int begin, end; };
P A[1005];
int flatten(int a, int b)
{
	switch (a)
	{
	case 1:
		return 100 + b;
	case 2:
		return 300 + (50 - b);
	case 3:
		return 400 + (50 - b);
	case 4:
		return 200 + b;
	}
}
int main()
{
	cin >> N; N /= 2;
	for (i = 0; i < N; i++)
	{
		cin >> m >> n >> p >> q;
		j = flatten(m, n); k = flatten(p, q);
		A[i] = { min(j,k), max(j,k) };
	}
	sort(A, A + N, [](P a, P b) {return a.begin < b.begin; });

	for (i = 0, p = 0; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{
#ifndef ONLINE_JUDGE
			cout << "CHK @ #" << i << "(" << A[i].begin << "-" << A[i].end << ") & #" << j << "(" << A[j].begin << '-' << A[j].end << ')' << '\n';
#endif

			if (A[i].begin > A[j].begin && A[i].begin < A[j].end && A[i].end > A[j].end) // intersection!
			{
#ifndef ONLINE_JUDGE
				cout << "INT @ " << i << " & " << j << '\n';
#endif
				p++;
				C[i]++; C[j]++;
			}
		}
	}
	cout << p << '\n' << *max_element(C, C + N);
	return 0;
}
