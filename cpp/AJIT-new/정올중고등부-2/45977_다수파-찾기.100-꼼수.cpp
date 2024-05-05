#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int i, j, k, l, N;
unordered_map<int, int>M;
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> k;
		if (++M[k] > N / 2)
		{
			cout << 1 << '\n' << k;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
