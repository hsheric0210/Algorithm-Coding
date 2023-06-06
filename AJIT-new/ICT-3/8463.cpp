// 회의실 배정
#include<iostream>
#include<algorithm>
using namespace std;
struct T { int beg, end; };
int i, j, k, l, N, p, q, r;
T V[100005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> j >> k;
		V[i] = { j,k };
	}

	// sort by length
	sort(V, V + N, [](T a, T b) {return (a.end == b.end && a.beg < b.beg) || (a.end < b.end); });
	
	j = V[0].end;
	for (i = k = 1; i < N; i++)
		if (V[i].beg >= j){ k++; j = V[i].end; } // switch to selected range
		else continue; // try next range
	cout << k;
	return 0;
}