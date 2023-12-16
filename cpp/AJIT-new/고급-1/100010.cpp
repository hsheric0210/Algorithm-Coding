/*
문제명: 책정리
교실: 고급-1
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;
int N, i, j, k, l, m, n, o, p, q, r;
char a;
vector<char>A, B, C; // C = 새로 꽃아야 하는 순서
int main()
{
	cin >> N;
	for (i = 0; i < N; i++) { cin >> a; A.push_back(a); }
	for (i = 0; i < N; i++) { cin >> a; C.push_back(a); }
	reverse(C.begin(), C.end()); // C의 back이 지금 당장 꺼내야 하는 원소를 의미하도록 뒤집기

	l = 0;
	while (!C.empty())
	{
		l++;
		k = find(A.begin(), A.end(), C.back()) != A.end(); // If the target is exist in A?
		if (!A.empty() && k)
		{
			if (A.back() == C.back())
			{
				A.pop_back(); // Pop
				C.pop_back();
#ifndef ONLINE_JUDGE
				cout << "pop" << '\n';
#endif
			}
			else
			{
				B.push_back(A.back()); // Push A->B
				A.pop_back();
#ifndef ONLINE_JUDGE
				cout << "push a->b" << '\n';
#endif
			}
		}
		else if (!B.empty())
		{
			// Push B->A
			A.push_back(B.back()); // Push A->B
			B.pop_back();
#ifndef ONLINE_JUDGE
			cout << "push b->a" << '\n';
#endif
		}
		else break;
	}
	cout << l;
	return 0;
}