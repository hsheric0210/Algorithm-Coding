/*
서로 다른 소수들의 합
https://43.200.211.173/contest/18/problem/80030
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef struct _A
{
	int sum;
	int lastnumber;
} A;
int i, j, k, n;
int isprime(int n)
{
	if (n <= 1)
		return 0;
	for (i = 2; i < (int)ceil(sqrt(n)); i++)
		if (n % i == 0)
			return 0;
	return 1;
}
void primes(int begin, int end, vector<int>* f)
{
	for (i = begin; i < end; i++)
	{
		int prime = 1;
		for (j = 2; j < (int)ceil(sqrt(i)); j++)
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
	vector<int>plist;
	primes(2, n, &plist);

	int count = 0;
	vector<vector<A>> t;
	for (i = 0; i < k; i++)
	{
		if (i == 0)
		{
			vector<A> init;
			for (auto a = plist.begin(); a != plist.end(); a++)
			{
				A tup = { *a, *a };
				init.push_back(tup);
			}
			t.push_back(init);
		}
		else
		{
			vector<A> prev = t[i - 1];
			vector<A> init;
			cout << "t[" << i << "].size=" << prev.size() << endl;
			for (auto a = prev.begin(); a != prev.end(); a++)
			{
				for (j = 0; j < plist.size(); j++)
				{
					if (plist[j] > a->lastnumber)
						break;
				}
				for (/*j = j*/; j < plist.size(); j++)
				{
					int b = plist[j];
					//if (b <= a->lastnumber) continue;
					int sum = a->sum + b;
					if (sum > n) break;
					init.push_back({ sum, b });
					if (i == k - 1 && sum == n)
						count++;
				}
			}
			t.push_back(init);
		}
	}

	cout << count << endl;

	// PRINT
	//for (i = 0; i < t.size(); i++)
	//{
	//	cout << "t[" << i << "]" << endl;
	//	for (auto a = t[i].begin(); a != t[i].end(); a++)
	//	{
	//		cout << "(" << a->sum << "-" << a->lastnumber << ")";
	//	}
	//	cout << endl;
	//}
	// PRINT
}