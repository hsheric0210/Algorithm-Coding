// 교집합과 합집합
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>
using namespace std;
int i, j, k, l, p, q, r, N, M;
set<int>A, B;
vector<int> U(200), I(100);
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> j;
		A.insert(j);
	}
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> j;
		B.insert(j);
	}

	//intersection
	auto in = set_intersection(A.begin(), A.end(), B.begin(), B.end(), I.begin());
	I.erase(in, I.end());
	if (I.empty())
		cout << 0 << '\n';
	else
	{
		for (int i : I)
			cout << i << ' ';
		cout << '\n';
	}

	//union
	auto un = set_union(A.begin(), A.end(), B.begin(), B.end(), U.begin());
	U.erase(un, U.end());
	for (int u : U)
		cout << u << ' ';
	return 0;
}