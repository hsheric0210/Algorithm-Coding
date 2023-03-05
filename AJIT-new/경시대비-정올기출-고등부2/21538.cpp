/*
초직사각형 - 정올2021
https://43.200.211.173/contest/17/problem/21538
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, n, a0, b0, c0, d0;
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
	cout << "Undefined char: " << ch << endl;
	return 0;
}
int* getvar(char ch)
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
	cout << "Undefined char: " << ch << endl;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k >> n >> a0 >> b0 >> c0 >> d0;
	for (i = 0; i < n; i++)
	{
		cin >> ch >> j;
		getarr(ch)->push_back(j);
	}
	
	// initial push
	for (i = 0; i < 4; i++)
	{
		auto ar = *getarr('A' + i);
		*getvar('A' + i) += *max_element(ar.begin(), ar.end()); // push maxes
	}


}