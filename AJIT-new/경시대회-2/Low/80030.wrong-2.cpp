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
using namespace std;
typedef struct _A
{
	int sum;
	int lastprime;
} A;
int i, j, k, l, m, n;
int isprime(int n)
{
	if (n <= 1)
		return 0;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
void primes(int begin, int end, vector<int>* f)
{
	for (i = begin; i < end; i++)
	{
		int prime = 1;
		for (j = 2; j < i; j++)
			if (i % j == 0)
				prime = 0;
		if (prime) f->push_back(i);
	}
}
int main()
{
	cin >> n >> k;

	if (k <= 1)
	{
		cout << isprime(n) << endl;
		return 0;
	}
	vector<int>prime_list;
	primes(2, n, &prime_list);

	int count = 0;
	vector<vector<A>> map;
	vector<A> init;
	for (auto a = prime_list.begin(); a != prime_list.end(); a++)
	{
		init.push_back({ *a, *a });
	}
	map.push_back(init);

	for (i = 1; i < k; i++)
	{
		// todo 24 찾더라도 중단 x
		vector<A> &prev = map[i - 1];
		vector<A> init;
		for (j = 0; j < prime_list.size(); j++)
		{
			int& prime = prime_list[j];
			for (l = 0; l < prev.size(); l++)
			{
/*
400 10
init[1].size=78
init[2].size=1810
init[3].size=20309
init[4].size=130842
init[5].size=546805
init[6].size=1533356
init[7].size=3065460
init[8].size=4345292
init[9].size=4472366
70184

400 10
init[1].size=78
init[2].size=1733
init[3].size=18582
init[4].size=112434
init[5].size=436097
init[6].size=1106188
init[7].size=1988061
init[8].size=2420416
init[9].size=2144319
70184
*/
				A prv_a = prev[l];
				if (prv_a.sum >= n) continue;//break;
				if (prime <= prv_a.lastprime) continue;
				int sum = prv_a.sum + prime;
				if (sum < n) init.push_back({ sum, prime });
				if (i == k - 1 && sum == n)
					count++;
			}
		}
		cout << "init[" << i << "].size=" << prev.size() << endl;
		map.push_back(init);
	}

	cout << count << endl;

	// PRINT
	//for (i = 0; i < map.size(); i++)
	//{
	//	cout << "t[" << i << "]" << endl;
	//	for (auto a = map[i].begin(); a != map[i].end(); a++)
	//	{
	//		cout << "(" << a->sum << "-" << a->lastprime << ")";
	//	}
	//	cout << endl;
	//}
	// PRINT
}