#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, N;
vector<int>A, B;
int ll(vector<int>V)
{
	vector<int>T;
	for (int a : V)
		if (T.empty() || T.back() < a)
			T.push_back(a);
		else
			*lower_bound(T.begin(), T.end(), a) = a;
	return T.size();
}
int main()
{
	cin >> N; for (i = 0; i < N; i++) { cin >> j; A.push_back(j); B.push_back(j); }
	reverse(B.begin(), B.end());
	k = ll(A); l = ll(B);
	if (k == l)
		cout << "IDGARA";
	else if (k > l)
		cout << "LEFT";
	else
		cout << "RIGHT";
	return 0;
}
