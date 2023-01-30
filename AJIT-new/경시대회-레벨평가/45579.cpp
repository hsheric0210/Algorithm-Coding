/*
연속적인 소수들의 합
https://43.200.211.173/contest/19/problem/45579
*/
#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
int i, j, k, l, n, * chk, * sums;
vector<int>primes;
int main()
{
	//erastones
	chk = new int[10001]{ 0 };
	for (i = 2, n = sqrt(10000); i <= n; i++)
		if (!chk[i])
			for (j = i * i; j <= 10000; j += i)
				chk[j] = 1;
	for (i = 2; i <= 10000; i++)
		if (!chk[i])
			primes.push_back(i);
	sums = new int[primes.size() + 1]{ 0 };

	cin >> n;
	int lb = 0, ub = 1;
	while (1)
	{
		int sum = accumulate(primes.begin() + lb, primes.begin() + ub, 0);
		if (sum < n)
		{
			ub++;
			if (primes.begin() + ub >= primes.end())
				break; // ub overflow failsafe
		}
		else if (sum > n)
		{
			lb++;
			if (lb >= ub || ub - lb >= primes.size())
				break; // lb overflow failsafe
		}
		else // sum == n
		{
			l++;
			ub++;
		}
	}
	cout << l << endl;
}