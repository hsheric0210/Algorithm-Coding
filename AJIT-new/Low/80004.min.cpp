/*
만년달력 만들기
https://43.200.211.173/contest/17/problem/80004
https://m.blog.naver.com/lovysunny7/221623688183
C-Minifier-friendly version
*/
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int i, j;
int ml[12] = { 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool ly(int y) { return y % 4 == 0 && y % 100 != 0 || y % 400 == 0; }
int lm(int y, int m)
{
	int d = ml[m - 1];
	if (d < 0) d = ly(y) ? 29 : 28;
	return d;
}
long long td(int y, int m, int d)
{
	long long t = 0;
	for (j = 1; j < y; j++) t += ly(j) ? 366 : 365;
	for (j = 1; j < m; j++) t += lm(y, j);
	return t + d;
}
int wd(int y, int m, int d) { return td(y, m, d) % 7; }
int main()
{
	char c; int y, m; cin >> y >> c >> m;
	for (i = 0; i < wd(y, m, 1); i++) cout << "   ";
	for (i = 1; i <= lm(y, m); i++)
	{
		cout << setw(3) << i;
		if (wd(y, m, i) == 6 && lm(y, m) != i)
			cout << endl;
	}
}