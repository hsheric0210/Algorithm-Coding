/*
ABBC-정올2022
http://ajit.co.kr/contest/28/problem/25038
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
int i, j, k, l;
deque<pair<char, bool>>s;
char _s[300005];
int main()
{
	cin >> _s;
	l = strlen(_s);
	for (i = 0; i < l; i++)
		s.push_back(make_pair(_s[i], 0)); // manual copy to linked list

	// drop 'BC'
	for (auto a = s.rbegin(); a != s.rend(); a++)
	{
		if (a->first == 'C')
		{
			auto b = find_if(a, s.rend(), [](pair<char, bool>a) {return a.first == 'B' && !a.second; });
			if (b == s.rend()) continue;
			a->second = 1;
			b->second = 1;
			j++;
		}
	}

	// drop 'AB'
	for (auto a = s.rbegin(); a != s.rend(); a++)
	{
		if (a->first == 'B' && !a->second)
		{
			auto b = find_if(a, s.rend(), [](pair<char, bool>a) {return a.first == 'A' && !a.second; });
			if (b == s.rend()) continue;
			a->second = 1;
			b->second = 1;
			j++;
		}
	}

	cout << j << endl;
}