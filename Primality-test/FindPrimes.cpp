/*
평소에 쓰던 '야매' 소수탐색 구현
*/
#include<iostream>
#include<vector>
#include<Windows.h> // for performance testing
using namespace std;
int i, j, k, n;
vector<int> prime;
/*
* 
100000
took 1734ms
9592

100000000
* failed to execute *

*/
int main()
{
	cin >> n;
	ULONGLONG tick = GetTickCount64();
	for (i = 2; i <= n; i++)
	{
		int isprime = 1;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isprime = 0;
				break;
			}
		}
		if (isprime)
			prime.push_back(i);
	}
	ULONGLONG delta = GetTickCount64() - tick;
	// print
	cout << "took " << delta << "ms" << endl;
	cout << prime.size() << endl;
	for (auto pr = prime.begin(); pr != prime.end(); pr++)
		cout << *pr << ' ';
	cout << endl;
}