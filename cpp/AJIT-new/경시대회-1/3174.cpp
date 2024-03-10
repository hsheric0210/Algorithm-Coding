/*
수 이어가기
https://43.200.211.173/contest/17/problem/3174
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<int> v;
	for (int i = n; i > 0; i--)
	{
		int a = n, b = i;
		vector<int> _v;
		_v.push_back(a);
		_v.push_back(b);
		while (true)
		{
			int c = a - b;
			if (c > 0)
			{
				a = b; b = c; // shift
				_v.push_back(c);
			}
			else
				break;
		}

		if (_v.size() > v.size())
			v = _v;
	}

	cout << v.size() << endl;
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << ' ';
	cout << endl;
}