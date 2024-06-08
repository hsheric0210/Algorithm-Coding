#include<iostream>
#include<iomanip>
#include<algorithm>
#include<utility>
#include<numeric>
#include<memory>
#include<vector>
#include<list>
#include<deque>
#include<bitset>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
int i, j, k, l, P, Q;
list<char>H;
int gcd(int p, int q)
{
	int r;
	while (1)
	{
		r = p % q;
		if (r == 0)
			return q;
		p = q;
		q = r;
	}
	return 1;
}
int corner()
{
	if (P % 2)
		if (Q % 2)
			return 3;
		else
			return 4;
	else
		if (Q % 2)
			return 2;
		else
			return 1;
}
int main() // 묘기 당구
{
	cin >> P >> Q;
	k = gcd(P, Q); P /= k; Q /= k;
	if (P > Q)
	{
		for (i = P; i <= P * Q; i += P)
		{
			list<char>T;
			for (j = i - i % Q; j > max(0, i - P); j -= Q)
			{
				if (j == P * Q) continue;
				T.push_back((j / Q % 2) ? 'N' : 'S');
			}
			H.insert(H.end(), T.rbegin(), T.rend());

			if (i < P * Q)
				H.push_back((i / P % 2) ? 'E' : 'W');
		}
	}
	else
	{
		for (i = Q; i <= P * Q; i += Q)
		{
			list<char>T;
			for (j = i - i % P; j > max(0, i - Q); j -= P)
			{
				if (j == P * Q) continue;
				T.push_back((j / P % 2) ? 'E' : 'W');
			}
			H.insert(H.end(), T.rbegin(), T.rend());

			if (i < P * Q)
				H.push_back((i / Q % 2) ? 'N' : 'S');
		}
	}
	cout << H.size() << '\n';
	for (char h : H)
		cout << h << ' ';
	cout << corner();
	return 0;
}
// 41분 21초 59 (...)
