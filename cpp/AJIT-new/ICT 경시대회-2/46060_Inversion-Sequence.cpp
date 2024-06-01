#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, N, A[1005];
vector<int>P;
int main()
{
	cin >> N; for (i = 1; i <= N; i++)cin >> A[i];
	P.push_back(0);
	P.push_back(N);
	for (i = N - 1; i > 0; i--)
	{
		for (j = k = 0; j < P.size(); j++)
		{
			if (P[j] > i)
				k++;
			if (k == A[i])
			{
				P.insert(P.begin() + j + 1, i);
				break;
			}
		}
	}
	for(auto itr=P.begin()+1;itr!=P.end();itr++)
		cout << *itr << ' ';
	return 0;
}
