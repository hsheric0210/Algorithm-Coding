#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int i, j, k, l, N;
deque<int>P, Q;
int main()
{
	cin >> N; while (N--) { cin >> j; P.push_back(j); }
	k = 1; // 다음에 꺼내야 할 자동차 번호
	while (true)
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
		else if (!P.empty())
		{
			Q.push_back(P.front());
			P.pop_front();
		}
		else
			break;
	}
	if (P.empty() && Q.empty())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
