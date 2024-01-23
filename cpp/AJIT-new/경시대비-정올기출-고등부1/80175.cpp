/*
비행기 촬영 계획
https://43.200.211.173/contest/17/problem/80175
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct _A
{
	int a, b, l;
	double avg;
} A;
vector<int>a;
vector<A>b;
bool c(A a, A b) { return a.avg > b.avg || a.avg == b.avg && a.l > b.l || a.avg == b.avg && a.l == b.l && a.a < b.a; }
int i, j, k, l, n, m, p, q, r;
int main()
{
	cin >> n >> m >> k;

	a.push_back(0); // prevent index-oob when reading a[i-1]
	for (i = 1; i <= n; i++)
	{
		cin >> j;
		a.push_back(a[i - 1] + j); // build sum tree
		// a[i] = i번째 입력까지의 총합
	}
	for (i = 1; i <= n - (k - 1); i++)
		for (j = i + (k - 1); j <= n; j++)
		{
			b.push_back({ i, j, j - i + 1, (double)(a[j] - a[i - 1]) / (j - i + 1) });
		}
	sort(b.begin(), b.end(), c);
	for (i = 0; i < min((int)b.size(), m); i++)
		cout << b[i].a << ' ' << b[i].b << endl;
}
