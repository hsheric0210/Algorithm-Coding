/*
문제명: 컬러볼
교실: 고급-2
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct A { int color, size, index; };
int N, Total, i, j, k, l, m, n, o, p, q, r, colorSum[200005], answers[200005]; A balls[200005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> p >> q;
		colorSum[p] += q;
		Total += q;
		balls[i] = { p, q, i };
	}
	sort(balls, balls + N, [](auto a, auto b) {return a.size == b.size ? a.color < b.color : a.size > b.size; });
	for (i = 0; i < N; i++)
	{
		auto size = balls[i].size;
		auto color = balls[i].color;
		for (j = i, k = 0, l = 0; j < N && size == balls[j].size; j++) if (color == balls[j].color) l++;
		auto sz_dup = j - i;
		answers[balls[i].index] = Total - colorSum[color] - size * sz_dup + size * l;
		Total -= size;
		colorSum[color] -= size;
	}
	for (i = 0; i < N; i++) cout << answers[i] << '\n';
	return 0;
}
