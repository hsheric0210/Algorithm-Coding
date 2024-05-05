#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
int i, j, k, l, N, A[100005], D[100005], P;
vector<int>B,V,C; // B:best, V:latest, C:carry-flag
int main()
{
	cin >> P;
	for (i = 1; i < P; i++) // i=1..(P-1)
	{
		// build
		V.clear(); C.clear();
		V.push_back(i); // Starting number
		C.push_back(0); C.push_back(0);
		while (true)
		{
			k = V.back() * 2 + C.back(); // 2mul+carry
			V.push_back(k % P);
			C.push_back(k / P);
			if (V.back() == V[0] && !C.back()) // cycle!
				break;
		}

#ifndef ONLINE_JUDGE
		cout << "start=" << i << " -> ";
		for (int v : V)
			cout << v << ' ';
		cout << '\n';
#endif

		// compare
	}
	return 0;
}
