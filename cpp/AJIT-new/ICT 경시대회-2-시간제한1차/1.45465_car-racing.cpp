#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int i, j, k, l, N;
list<int>P, Q, R;
int main()
{
	cin >> N;
	while (N--) { cin >> i; P.push_back(i); }
	// k = next car num.
	k = 1;
	while (!P.empty() || !Q.empty())
	{
		if (!P.empty() && P.front() == k)
		{
			P.pop_front();
			k++;
		}
		else if (!Q.empty() && Q.front() == k)
		{
			Q.pop_front();
			k++;
		}
		else
		{
			Q.push_back(P.front());
			P.pop_front();
		}

		if (P.empty() && !Q.empty() && Q.front() != k)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}
