// ICT-1 : �ܾ� ����
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
int i, j, k, l, p, q, r, x, y, z, m, n;
auto cmp = [](string a, string b) {return a.length() < b.length() || a.length() == b.length() && a < b; };
set<string,decltype(cmp)>S(cmp);
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		S.insert(s);
	}
	for (auto a : S)
		cout << a << '\n';
	return 0;
}