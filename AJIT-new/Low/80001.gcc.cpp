/*
문자열 구간뒤집기
https://43.200.211.173/contest/17/problem/80001
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	string s; cin >> s;
	int c; cin >> c; 
	for (int l = 0; l < c; l++)
	{
		int i, j; cin >> i >> j;
		int t = i;
		i = min(i, j); j = max(t, j); // failsafe
		reverse(s.begin() + i - 1, s.begin() + j);
	}
	cout << s << endl;
	return 0;
}