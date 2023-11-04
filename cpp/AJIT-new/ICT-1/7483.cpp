// ICT-1 : 단어 정렬
// 그냥 정렬 함수 구현... 그리고 STL set 사용하는 것 잊지 말 것!
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