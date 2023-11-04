/*
서로 다른 소수들의 합
https://43.200.211.173/contest/18/problem/80030


FIXME

512 10
prev[0].size=97
prev[1].size=2741
prev[2].size=37287
prev[3].size=295615
prev[4].size=1532706
prev[5].size=5410537
prev[6].size=13804679
prev[7].size=25502458
prev[8].size=35221526
691729
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<Windows.h> // for debugging
using namespace std;
typedef struct _A
{
	int sum;
	int last_appended_prime;
} A;
bool apred(A a, A b)
{
	return a.sum == b.sum && a.last_appended_prime == b.last_appended_prime;
}
int i, j, k, l, m, n;
int isprime(int num)
{
	if (num <= 1)
		return 0;
	for (l = 2; l < num; l++)
		if (num % l == 0)
			return 0;
	return 1;
}
void primes(vector<A>* f)
{
	for (i = 2; i < n; i++)
		if (isprime(i))
			f->push_back({ i, i });
}
int main()
{
	cin >> n >> k;

	if (k <= 1)
	{
		cout << isprime(n) << endl;
		return 0;
	}
	int count = 0;
	vector<A>* map = new vector<A>[k];
	primes(&map[0]);

	for (i = 1; i < k; i++)
	{
		vector<A>& prev = map[i - 1];
		vector<A> init;
		int tick = GetTickCount64();
		for (j = 0; j < map[0].size(); j++)
		{
			int& prime = map[0][j].last_appended_prime;
			for (l = 0; l < prev.size(); l++)
			{
				A prv_a = prev[l];
				//if (prv_a.sum >= n) break;
				if (prime <= prv_a.last_appended_prime) continue;
				int sum = prv_a.sum + prime;
				if (sum < n && sum + 2 * (k - i - 1) <= n) init.push_back({ sum, prime });
				if (i == k - 1 && sum == n)
					count++;
			}
		}
		int tickdelta = GetTickCount64() - tick;
		cout << "init[" << i << "] took " << tickdelta << "ms" << endl;
		cout << "init[" << i << "] took " << ((double)tickdelta * 1000.0 * 1000.0 / init.size()) << "ns per element" << endl;
		cout << "init[" << i << "].size=" << init.size() << endl;
		map[i] = init;
	}

	cout << count << endl;

	// PRINT
	for (i = 0; i < k; i++)
	{
		cout << "t[" << i << "]" << endl;
		for (auto a = map[i].begin(); a != map[i].end(); a++)
		{
			cout << "(" << a->sum << "-" << a->last_appended_prime << ")";
		}
		cout << endl;
	}
	// PRINT
}