/*
떡 먹는 호랑이
https://43.200.211.173/contest/17/problem/3041
소요시간: 약 1시간 반
백준 정답 처리됨 (문제 2502 제출번호 55894514)
*/
#include<iostream>
using namespace std;
int i, j, k, l, n, d, t;
int fib[35];
int main()
{
	fib[1] = 1;
	for (int i = 2; i < 35; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> d >> k;
	d--;
	for (i = 1;; i++)
	{
		l = (k - fib[d - 1] * i) / fib[d];
		if (l < i) // A>B가 되면 중지
			break;
		if ((k - fib[d - 1] * i) % fib[d] == 0) // 정수로 나누어떨어지면 저장
		{
			n = i; t = l;
			break; // A가 가장 작은 값을 출력하기 위하여
		}
	}
	cout << n << endl << t << endl;
}