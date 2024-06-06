#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, N, P, Q;
vector<char>V, H;
int gcd(int p, int q)
{
	int r, s;
	s = min(p, q);
	p = max(p, q);
	q = s;
	while (1)
	{
		r = p % q;
		if (!r)
			return q;
		p = q;
		q = r;
	}
	return 1;
}
int endp(int p, int q)
{
	if (p % 2)
	{
		if (q % 2) return 3;
		else return 4;
	}
	else
	{
		if (q % 2) return 2;
		else return 1;
	}
}
int main()
{
	cin >> P >> Q;
	j = gcd(P, Q); P /= j; Q /= j;
	if (P > Q)
	{
		// 세로로 올라감
		for (i = P; i <= P * Q; i += P)
		{
			V.clear();
			for (k = i / Q * Q; k > i - P; k -= Q)
			{
				if (k == i && k == P * Q) continue;
				V.push_back(k / Q % 2 ? 'N' : 'S');
			}
			H.insert(H.end(), V.rbegin(), V.rend());
			if (i < P* Q)
				H.push_back(i / P % 2 ? 'E' : 'W');
		}
	}
	else // if (P<Q)
	{
		// 가로로 오른쪽으로 감
		for (i = Q; i <= P * Q; i += Q)
		{
			V.clear();
			for (k = i / P * P; k > i - Q; k -= P)
			{
				if (k == i && k == P * Q) continue;
				V.push_back(k / P % 2 ? 'E' : 'W');
			}
			H.insert(H.end(), V.rbegin(), V.rend());
			if (i < P * Q)
				H.push_back(i / Q % 2 ? 'N' : 'S');
		}
	}

	cout << H.size() << '\n';
	for (i = 0; i < H.size(); i++)
		cout << H[i] << ' ';
	cout << endp(P, Q);
	return 0;
}
