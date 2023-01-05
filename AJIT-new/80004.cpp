/*
만년달력 만들기
https://43.200.211.173/contest/17/problem/80004
https://m.blog.naver.com/lovysunny7/221623688183
*/
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int monthLengthLookup[12] = { 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isLeapYear(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int lengthOfMonth(int year, int month)
{
	int d = monthLengthLookup[month - 1];
	if (d < 0) d = isLeapYear(year) ? 29 : 28;
	return d;
}
long long totalDays(int year, int month, int day)
{
	long long t = 0;
	for (int i = 1; i < year; i++)
		t += isLeapYear(i) ? 366 : 365;
	for (int i = 1; i < month; i++) t += lengthOfMonth(year, i);
	return t + day;
}
int weekDayOf(int year, int month, int day)
{
	return totalDays(year, month, day) % 7;
}
int main()
{
	char ch; int y, m; cin >> y >> ch >> m;

	// 1st day padding
	for (int i = 0; i < weekDayOf(y, m, 1); i++)
		cout << "   ";
	for (int i = 1; i <= lengthOfMonth(y, m); i++)
	{
		cout << setw(3) << i;
		if (weekDayOf(y, m, i) == 6 // 금요일
			&& lengthOfMonth(y, m) != i // 당월 마지막 날 아님
			)
			cout << endl;
	}
}