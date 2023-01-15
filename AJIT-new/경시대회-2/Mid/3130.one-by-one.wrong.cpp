/*
숫자카드
https://43.200.211.173/contest/18/problem/3130
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
//#include<set>
using namespace std;
typedef struct _str
{
	vector<int> vec;
	int pos;
} str;
void dump_v(vector<vector<str>> v)
{
	for (int i = 0, j = v.size(); i < j; i++)
	{
		auto a = v[i];
		cout << "dump for degree " << i << endl;
		for (int k = 0, l = a.size(); k < l; k++)
		{
			auto b = a[k];
			cout << "merge #" << k << " (pos offset=" << b.pos << ')' << endl;;
			for (int m = 0, n = b.vec.size(); m < n; m++)
			{
				cout << b.vec[m] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

	char* num = new char[45]{ 0 };
	cin.getline(num, 45);
	int len = strlen(num);

	int avail_count = 1;
	vector<str> first;
	vector<int> initial;
	for (int i = 0; i < len; i++)
		initial.push_back(num[i] - '0');
	first.push_back({ initial , 0 });

	vector<vector<str>> v;
	v.push_back(first);
	int degree = 1;
	while (true)
	{
		bool somethingAdded = false;
		vector<str> &prev_deg = v[degree - 1];
		vector<str> deg;
		for (int l = 0, m = prev_deg.size(); l < m; l++)
		{
			str &sa = prev_deg[l];
			vector<int> &a = sa.vec;
			for (int pos = sa.pos, limit = a.size() - 1; pos < limit; pos++)
			{
				vector<int> b;
				if (a[pos] >= 10 || a[pos + 1] >= 10 || a[pos] * 10 + a[pos + 1] > 34) // unable to merge
					continue;

				for (int i = 0, j = a.size(); i < j; i++)
				{
					int ans = a[i];
					if (i == pos)
					{
						ans = a[pos] * 10 + a[pos + 1]; // pos의 숫자와 pos+1의 숫자 합치기
					}
					else if (i == pos + 1)
						continue;
					b.push_back(ans);
				}
				deg.push_back({ b ,pos });
				somethingAdded = true;
				avail_count++;
			}
		}
		v.push_back(deg);
		degree++;
		if (!somethingAdded)
			break;
	}
	//dump_v(v);
	cout << avail_count << endl;
}
