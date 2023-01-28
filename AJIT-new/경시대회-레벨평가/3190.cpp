/*
주식 투자
https://43.200.211.173/contest/19/problem/3190
*/
#include<iostream>
#include<cmath>
using namespace std;
int a, b, i, j, k, l;
double n, m;
int main()
{
	cin >> a >> b;
	n = a;
	for (i = 0; i < b; i++)
	{
		cin >> j;
		n = n * (j + 100) / 100;
	}
	m = n - a;
	cout << (int)round(m) << endl; // round 대신 rint 쓰는 바람에 1 실패 적립 (rint(1.5)=1.0, round(1.5)=2.0 자세한 사항은 다음 참조: https://stackoverflow.com/questions/37256550)
	if (m <= -.5)
		cout << "bad" << endl;
	else if (m >= .5)
		cout << "good" << endl;
	else
		cout << "same" << endl;
}