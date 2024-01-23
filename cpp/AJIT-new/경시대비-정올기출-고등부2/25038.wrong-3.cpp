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
deque<char>s2;
char _s[300005];
int normal()
{
	while (s2.size() > 1)
	{
		if (s2.size() > 2 && s2[0] == 'A' && s2[1] == 'B' && s2[2] == 'C') // abc -> del 'bc'
		{
			s2.erase(s2.begin() + 1, s2.begin() + 3);
			j++;
		}
		else
		{
			char front = s2.front();
			s2.pop_front();
			switch (front)
			{
			case 'A': // ab
			{
				auto b = find(s2.begin(), s2.end(), 'B');
				if (b == s2.end()) continue;
				s2.erase(b);
				j++;
				break;
			}
			case 'B': // bc
			{
				auto c = find(s2.begin(), s2.end(), 'C');
				if (c == s2.end()) continue;
				s2.erase(c);
				j++;
				break;
			}
			}
		}
	}
	return j;
}
int reversed()
{
	// drop 'BC'
	for (auto a = s.rbegin(); a != s.rend(); a++)
	{
		if (a->first == 'C')
		{
			auto b = find_if(a, s.rend(), [](pair<char, bool>a) {return a.first == 'B' && !a.second; });
			if (b == s.rend()) continue;
			a->second = 1;
			b->second = 1;
			k++;
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
			k++;
		}
	}
	return k;
}
int main()
{
	cin >> _s;
	l = strlen(_s);
	for (i = 0; i < l; i++)
	{
		s.push_back(make_pair(_s[i], 0)); // manual copy to linked list
		s2.push_back(_s[i]);
	}
	cout << max(normal(), reversed()) << endl;
}