// ICT-1 : 요세푸스 문제
#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;
int i, j, k, l, p, q, r, m, n;
deque<int>Q1,Q2;
int main()
{
	cin >> n>>k;
	for (i = 0; i < n; i++)
		Q1.push_back(i + 1);
	for (i = 0; i < n; i++)
	{
		p = (p + k-1) % Q1.size();
		Q2.push_back(Q1[p]);
		Q1.erase(Q1.begin() + p);
	}
	cout << '<';
	for(i = 0, j = Q2.size(); i < j-1; i++)
			cout << Q2[i] << ", ";
	cout << Q2[j-1] << '>';
	return 0;
}