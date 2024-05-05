#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<iomanip>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, N;
struct P { int i, v; };
deque<P>D;
int main()
{
	cin >> N;
	D.push_back({ 0,0 }); // initial
	for (i = 1; i <= N; i++)
	{
		cin >> m;
		while (!D.empty() && D.back().v > m) // pop until 'stack top <= m'
		{
			P b = D.back();
			D.pop_back();
			l = max(l, b.v * (i - D.back().i - 1));
		}
		D.push_back({ i, m });
	}
	while (D.size() > 1) // pop all
	{
		P b = D.back();
		D.pop_back();
		l = max(l, b.v * (i - D.back().i - 1));
	}
	cout << l;
	return 0;
}
