/*
초직사각형 - 정올2021
https://43.200.211.173/contest/17/problem/21538
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define UL unsigned long long
using namespace std;
int i, j, k, l, n;
UL a0, b0, c0, d0;
char ch;
vector<int>a, b, c, d;
vector<int>* getarr(char ch)
{
	switch (ch)
	{
	case 'A':
		return &a;
	case 'B':
		return &b;
	case 'C':
		return &c;
	case 'D':
		return &d;
	}
	cout << "Undefined arr char: " << ch << endl;
	return 0;
}
UL* getvar(char ch)
{
	switch (ch)
	{
	case 'A':
		return &a0;
	case 'B':
		return &b0;
	case 'C':
		return &c0;
	case 'D':
		return &d0;
	}
	cout << "Undefined var char: " << ch << endl;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> a0 >> b0 >> c0 >> d0;
	for (i = 0; i < n; i++)
	{
		cin >> ch >> j;
		getarr(ch)->push_back(j);
	}

	// sort arrays; this will always take a long time
	for (i = 0; i < 4; i++)
	{
		auto ar = getarr('A' + i);
		sort(ar->begin(), ar->end(), less<int>());
	}
	
	for (i = 0; i < k; i++)
	{
		vector<int>tmp2;
		for (j = 0; j < 4; j++)
			if (!getarr('A' + j)->empty())
				tmp2.push_back(j);
		int maxidx = *max_element(tmp2.begin(), tmp2.end(), [](int a, int b) {return *getvar('A' + a) > *getvar('A' + b); });
		auto ar = getarr('A' +  maxidx);
		j = ar->back();
		*getvar('A' + maxidx) += j; // push maxes
		ar->pop_back(); // remove applied entry
		cout << (char)('A' + maxidx) << ' ' << j << endl;
	}
}