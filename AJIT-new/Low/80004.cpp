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
bool isLeapYear(int year) { return year % 4 == 0 && year % 100 != 0 || year % 400 == 0; }
int lengthOfMonth(int year, int month)
{
	int days = monthLengthLookup[month - 1];
	if (days < 0) days = isLeapYear(year) ? 29 : 28;
	return days;
}
long long totalDays(int year, int month, int day)
{
	long long days = 0;
	for (int i = 1; i < year; i++)		days += isLeapYear(i) ? 366 : 365;
	for (int i = 1; i < month; i++) days += lengthOfMonth(year, i);
	return days + day;
}
int weekDayOf(int year, int month, int day) { return totalDays(year, month, day) % 7; }
int main()
{
	char _; int year, month; cin >> year >> _ >> month;

	// 1st day padding
	for (int i = 0; i < weekDayOf(year, month, 1); i++)		cout << "   ";
	for (int i = 1; i <= lengthOfMonth(year, month); i++)
	{
		cout << setw(3) << i;
		if (weekDayOf(year, month, i) == 6 // 금요일
			&& lengthOfMonth(year, month) != i // 당월 마지막 날 아님
			)
			cout << endl; // newline
	}
}