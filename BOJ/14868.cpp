// ¹®¸í - Union-find
// in progress...
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
struct T { int a, b; };
struct V { int a, b, p, q; };
int i, j, k, l, p, q, r, N, K;
T M[2000][2000];
vector<V>buf;
void StayCivilized(V a)
{
	if (a.a <= 0 || a.b <= 0 || a.a > N || a.b > N)
		return;
	if (M[a.a][a.b].a != 0 && M[a.a][a.b].b != 0 && (M[a.a][a.b].a != a.p || M[a.a][a.b].b != a.q)) // this region is civilized and met other civilization
		M[a.a][a.b] = { min(M[a.a][a.b].a, a.p), min(M[a.a][a.b].b, a.q) }; // the smaller number, the better civilization
	else
		M[a.a][a.b] = { a.p,a.q };
}
int main()
{
	cin >> N >> K;
	for (i = 0; i < K; i++)
	{
		cin >> p >> q;
		M[p][q] = { p,q };
	}

	r = 1;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
			cout << setw(6) << '(' << M[i][j].a << ',' << M[i][j].b << ") ";
		cout << '\n';
	}

	while (1)
	{
		//check all filled
		k = l = 0;
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (M[i][j].a != 0 && M[i][j].b != 0 && k == 0 && l == 0)
				{
					k = M[i][j].a;
					l = M[i][j].b;
				}
				else if (M[i][j].a != k || M[i][j].b != l) // different union found! -> NOT FINISHED
				{
					goto notFinished;
				}
		break; // Every CIVIL is connected
	notFinished:
		//bfs&uf
		buf.clear();
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
			{
				p = M[i][j].a, q = M[i][j].b;
				if (p != 0 && q != 0)
				{
					buf.push_back({ i - 1, j, p, q });
					buf.push_back({ i + 1, j, p, q });
					buf.push_back({ i, j - 1, p, q });
					buf.push_back({ i, j + 1, p, q });
				}
			}
		for (V a : buf)
			StayCivilized(a);

		// dump table
		cout << '\n';
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
				cout << setw(6) << '(' << M[i][j].a << ',' << M[i][j].b << ") ";
			cout << '\n';
		}
		r++;
	}
	cout << r;
}