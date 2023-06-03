// ÀÌÄ£¼ö
#include<iostream>
using namespace std;
int i, j, k, l;
unsigned long long A[105];
int main()
{
	// Fibonacci
	A[1] = 1;
	for (i = 0; i <= 100; i++)
		A[i + 2] = A[i] + A[i + 1];
	cin >> i;
	cout << A[i] << '\n';
	return 0;
}