/*
피보나치 함수
https://www.acmicpc.net/problem/1003
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _fibonacci
{
	int fib;
	int zero;
	int one;

	struct _fibonacci operator+(struct _fibonacci other)
	{
		return { fib + other.fib, zero + other.zero, one + other.one };
	}
} fibonacci;

int main(void)
{
	int n;
	cin >> n;

	int* inputs = new int[n]();

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		inputs[i] = x;
	}

	int max = *max_element(inputs, inputs + n);

	fibonacci* fib = new fibonacci[max + 1]();
	fibonacci def = { 0, 0, 0 };
	fill(fib, fib + max, def);
	fib[0] = { 0, 1, 0 };
	fib[1] = { 1, 0, 1 };

	for (int i = 2; i <= max; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	for (int i = 0; i < n; i++)
	{
		fibonacci f = fib[inputs[i]];
		cout << f.zero << " " << f.one << endl;
	}

	delete[] inputs; // forgot to free
	delete[] fib;
}