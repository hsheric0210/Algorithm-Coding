/*
만능 휴지통
https://43.200.211.173/contest/19/problem/3141
*/
#include<iostream>
using namespace std;
int n, m, x, y;
int main()
{
	cin >> n;
	int x = n / 10;
	int y = n % 10;
	int m = (y * 10 + x) * 2;
	if (m >= 100) // 구현 실수 I: 문제를 제대로 읽지 않아, '100을 넘을 때, 100자리 위는 고려하지 않는다'라는 사항을 그대로 빠뜨리는 바람에 1실패 적립
		m %= 100;
	cout << m << endl;
	if (m <= 50)
		cout << "GOOD" << endl;
	else
		cout << "OH MY GOD" << endl;
}