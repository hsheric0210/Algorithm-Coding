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
int main()
{
	cin >> _s;
	l = strlen(_s);
	s.push_back(0); // push empty char to prevent first pointer(a.begin) from being invalidated
	for (i = 0; i < l; i++)
		s.push_back(_s[i]); // manual copy to linked list

	for (auto a = s.begin() + 1; a != s.end(); a++)
	{
		if (*(a - 1) == 'A' && *a == 'B' && *(a + 1) == 'C') // ABC
		{
			k++;
			if (*(a + 2) == 'B') // ab -> better
			{
				s.erase(a - 1, a);
				continue;
			}

			if (i > 2 && *(a - 2) == 'B') // bc -> better
			{
				s.erase(a, a + 1);
				a++; // prevent accessing to deleted 'a+1'
				continue;
			}
		}
		if (*(a - 1) == 'A' && *a == 'B') // ab
		{
			s.erase(a - 1, a);
			k++;
		}
		if (*(a - 1) == 'B' && *a == 'C') // bc
		{
			s.erase(a - 1, a);
			k++;
		}
	}
	cout << k << endl;
}