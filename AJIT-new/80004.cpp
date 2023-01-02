/*
만년달력 만들기
https://43.200.211.173/contest/17/problem/80004
https://m.blog.naver.com/lovysunny7/221623688183
*/
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int mlt[12] = { 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool islp(int y)
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}
int mlen(int y, int m)
{
	int d = mlt[m - 1];
	if (d < 0) d = islp(y) ? 29 : 28;
	return d;
}
long long tday(int y, int m, int d)
{
	long long t = 0;
	for (int i = 1; i < y; i++)
		t += islp(i) ? 366 : 365;
	for (int i = 1; i < m; i++) t += mlen(y, i);
	return t + d;
}
int wday(int y, int m, int d)
{
	return tday(y, m, d) % 7;
}
int main()
{
	char ch; int y, m; cin >> y >> ch >> m;

	// 1st day padding
	for (int i = 0; i < wday(y, m, 1); i++)
		cout << "   ";
	for (int i = 1; i <= mlen(y, m); i++)
	{
		cout << setw(3) << i;
		if (wday(y, m, i) == 6 // 금요일
			&& mlen(y, m) != i // 당월 마지막 날 아님
			)
			cout << endl;
	}
}