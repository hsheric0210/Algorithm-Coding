/*
ABBC-정올2022
http://ajit.co.kr/contest/28/problem/25038
*/
#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
char s[300005];
deque<int>q[3];
int i, j, k;
int main()
{
	cin >> s;
	for (i = 0, j = strlen(s); i < j; i++)
		q[s[i] - 'A'].push_back(i);
	while (!q[1].empty() && !q[2].empty()) // BC
	{
		if (q[1].front() < q[2].front())
		{
			k++;
			q[1].pop_front();
		}
		q[2].pop_front();
	}

	while (!q[0].empty() && !q[1].empty()) // AB
	{
		if (q[0].front() < q[1].front())
		{
			k++;
			q[0].pop_front();
		}
		q[1].pop_front();
	}

	cout << k << '\n';
}