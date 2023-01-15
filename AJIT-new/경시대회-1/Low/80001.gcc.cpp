/*
문자열 구간뒤집기
https://43.200.211.173/contest/17/problem/80001
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m, l, x, y; string s;
int main()
{
	cin >> n >> s >> m;
	for (l = 0; l < m; l++)
	{
		cin >> x >> y;
		reverse(s.begin() + min(x, y) - 1, s.begin() + max(x, y));
	}
	cout << s << endl;
}