/*
(평소에 쓰던 '야매' 소수탐색 구현이 아닌)
공식적인 에라스토네스의 체 구현
*/
#include<iostream>
#include<vector>
#include<Windows.h> // for performance testing
using namespace std;
int i, j, k, n, * chk;
vector<int> prime;
/*

100000
took 0ms
9592

100000000
took 4469ms
5761455

*/
int main()
{
	cin >> n;
	ULONGLONG tick = GetTickCount64();
	chk = new int[n + 1]{ 0 };
	chk[0] = chk[1] = 1; // 0, 1은 소수가 아님
	// Build a sieve: O(n^2)
	for (i = 2, j = (int)ceil(sqrt(n)); i <= j; i++)
		if (!chk[i])
			for (k = i + i; k <= n; k += i) // 주목: k=값을 초기화하는 부분에서, 'k=i*i'이 아니라 'k=i+i'임에 주목하라
				chk[k] = 1;
	//  filter out only primes: O(n)
	for (i = 1; i <= n; i++)
		if (!chk[i])
			prime.push_back(i);
	ULONGLONG delta = GetTickCount64() - tick;
	// print
	cout << "took " << delta << "ms" << endl;
	cout << prime.size() << endl;
	for (auto pr = prime.begin(); pr != prime.end(); pr++)
		cout << *pr << ' ';
	cout << endl;
}