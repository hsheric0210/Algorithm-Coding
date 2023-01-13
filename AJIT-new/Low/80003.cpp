/*
삼각형 만들기
https://43.200.211.173/contest/17/problem/80003
https://blockdmask.tistory.com/196
*/
#include <iostream>
using namespace std;
int n, a, b, c, d = 0;
int main()
{
	cin >> n;
	if (!(n < 3 || n == 4))
		for (a = 1; a <= n / 3; a++) // a: 1..(n/3)
		{
			for (b = a; b <= n / 2; b++) // b: a..(n/2)
			{
				c = n - a - b;
				if (c < b)
					break; // 합동인 3가지의 삼각형 중에서, C가 가장 큰 하나의 경우만 선택
				if (a + b > c) // 삼각형의 형성조건을 만족하는지 검사
					d++;
			}
		}
	cout << d << endl;
	return 0;
}