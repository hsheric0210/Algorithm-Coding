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
deque<char>s;
char _s[300005];
void dmp()
{
	for (auto a = s.begin(); a != s.end(); a++)
		cout << *a;
}
int main()
{
	cin >> _s;
	l = strlen(_s);
	for (i = 0; i < l; i++)
		s.push_back(_s[i]); // manual copy to linked list

	while (s.size() > 1)
	{
		//dmp();
		//cout << " -> ";
		if (s.size() > 2 && s[0] == 'A' && s[1] == 'B' && s[2] == 'C') // abc -> del 'bc'
		{
			//cout << "del 'bc'(abc)";
			s.erase(s.begin() + 1, s.begin() + 3);
			j++;
		}
		else
		{
			char front = s.front();
			s.pop_front(); //s.erase(s.begin());
			switch (front)
			{
			case 'A': // ab
			{
				auto b = find(s.begin(), s.end(), 'B');
				if (b == s.end()) continue;
				s.erase(b);
				j++;
				//cout << "del 'ab'";
				break;
			}
			case 'B': // bc
			{
				auto c = find(s.begin(), s.end(), 'C');
				if (c == s.end()) continue;
				s.erase(c);
				j++;
				//cout << "del 'bc'";
				break;
			}
			}
		}
		//cout << " -> ";
		//dmp();
		//cout << endl;
	}

	cout << j << endl;
}