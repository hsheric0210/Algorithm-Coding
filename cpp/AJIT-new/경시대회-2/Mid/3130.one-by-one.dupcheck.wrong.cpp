/*
숫자카드
https://43.200.211.173/contest/18/problem/3130
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include<set>
using namespace std;
void dump_v(vector<vector<vector<int>>> v)
{
	for (int i = 0, j = v.size(); i < j; i++)
	{
		auto a = v[i];
		cout << "dump for degree " << i << endl;
		for (int k = 0, l = a.size(); k < l; k++)
		{
			auto b = a[k];
			cout << "merge #" << k << endl;;
			for (int m = 0, n = b.size(); m < n; m++)
			{
				cout << b[m] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	char* num = new char[45]{ 0 };
	cin.getline(num, 45);
	int len = strlen(num);

	int avail_count = 1;
	vector<vector<int>> first;
	vector<int> initial;
	for (int i = 0; i < len; i++)
		initial.push_back(num[i] - '0');
	first.push_back(initial);

	vector<vector<vector<int>>> v;
	vector<vector<int>> dupcheck; // https://stackoverflow.com/a/46128321
	v.push_back(first);
	int degree = 1;
	while (true)
	{
		bool somethingAdded = false;
		vector<vector<int>> prev_deg = v[degree - 1]; // this is copy, not reference
		vector<vector<int>> deg;
		for (int l = 0, m = prev_deg.size(); l < m; l++)
		{
			vector<int> a = prev_deg[l];
			for (int pos = 0, limit = a.size() - 1; pos < limit; pos++)
			{
				vector<int> b;
				if (a[pos] >= 10 || a[pos + 1] >= 10 || a[pos] * 10 + a[pos + 1] > 34) // unable to merge
					continue;

				for (int i = 0, j = a.size(); i < j; i++)
				{
					int ans = a[i];
					if (i == pos)
						ans = a[pos] * 10 + a[pos + 1]; // pos의 숫자와 pos+1의 숫자 합치기
					else if (i == pos + 1)
						continue;
						b.push_back(ans);
				}
				bool anydup = false;
				for (auto d = dupcheck.begin(); d != dupcheck.end(); d++)
				{
					if (equal(d->begin(), d->end(), b.begin(), b.end()))
					{
						anydup = true;
						break;
					}
				}
				if (!anydup)
				{
					deg.push_back(b);
					dupcheck.push_back(b);
					somethingAdded = true;
					avail_count++;
				}
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
