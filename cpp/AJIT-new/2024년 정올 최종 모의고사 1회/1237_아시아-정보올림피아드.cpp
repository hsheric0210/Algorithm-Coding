#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, N, M[1005];
struct P { int country, id, score; };
vector<P>V;
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> j >> k >> l;
		V.push_back({ j,k,l });
	}
	sort(V.begin(), V.end(), [](P a, P b) {return a.score < b.score; });

	k = 0;
	while (k < 3 && !V.empty())
	{
		P top = V.back();
		V.pop_back();
		if (M[top.country]++ >= 2) // maximum medal count limit
			continue;
		cout << top.country << ' ' << top.id << '\n';
		k++;
	}
	return 0;
}
