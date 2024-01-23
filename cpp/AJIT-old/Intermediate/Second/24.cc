/* 중급(上) 24. 꿀벌탈출 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Simple but can raise Stack Overflow
int fib_recr(int i)
{
	return (i <= 1) ? i : (fib_recr(i - 1) + fib_recr(i - 2));
}

// More complicated but safe from Stack Overflow
int fib_nonrecr(int n)
{
	// Code from 'https://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C'
	int first = 0;
	int second = 1;
	int counter = 2; 
	while (counter < n)
	{
		int temp = second;
		second += first;
		first = temp;
		++counter;
	}
	if (n == 0)
		return 0;
	else
		return first + second;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);
	printf("fib for %d\n", n);
	fprintf(out, "%d", fib_nonrecr(n));

	fclose(in);
	fclose(out);
	return 0;
}
