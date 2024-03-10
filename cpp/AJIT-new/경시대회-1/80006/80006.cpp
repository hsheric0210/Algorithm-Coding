/*
Guessing Game
https://43.200.211.173/contest/17/problem/80006
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int m = 1 // 추론 가능한 수의 최솟값
		, M = 10 // 추론 가능한 수의 최댓값
		, s = 0; // If the imposter is SUS
	int n;
	char str[50]{ 0 };
	while (true)
	{
		cin.getline(str, 50);
		n = atoi(str);
		cin.getline(str, 50);
		if (strcmp(str, "too high") == 0)
		{
			if (n < m)
				s = 1;
			M = std::min(n - 1, M);
			if (m > M)
				s = 1;
		}
		else if (strcmp(str, "too low") == 0)
		{
			if (n > M)
				s = 1;
			m = std::max(m, n + 1);
			if (m > M)
				s = 1;
		}
		else if (strcmp(str, "right on") == 0)
		{
			if (n < m || n > M)
				s = 1;
			break;
		}
		else
		{
			cout << "unknown answer: " << str << endl;
			return 1;
		}
	}
	if (s)
		cout << "Stan is dishonest" << endl;
	else
		cout << "Stan may be honest" << endl;
	return 0;
}