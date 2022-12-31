/*
2×n 타일링
https://www.acmicpc.net/problem/11726
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	// Bottom-up fibonacci implemenation
	int* fib = new int[n + 1]();
	fib[1] = 1;
	fib[2] = 2;

	for (int i = 3; i <= n; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 10007;

	cout << fib[n] % 10007 << endl;

	delete[] fib;
}