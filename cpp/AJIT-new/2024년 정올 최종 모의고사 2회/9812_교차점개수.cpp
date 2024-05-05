#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, N;
struct P { int x1, y1, x2, y2; };
P T[55];
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> m >> n >> p >> q;
		T[i] = { m,n,p,q };
	}
	return 0;
}
