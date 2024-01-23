/*
Guessing Game
https://43.200.211.173/contest/19/problem/45455
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int lower = 1, upper = 10, sus; // both boundary is inclusive
int main()
{
	char question[50];
	char answer[50];
	while (true)
	{
		cin.getline(question, 50);
		int nq = atoi(question);
		cin.getline(answer, 50);
		if (!strcmp(answer, "too high"))
		{
			sus |= nq - 1 < lower;
			upper = min(nq - 1, upper);
		}
		else if (!strcmp(answer, "too low"))
		{
			sus |= nq + 1 > upper;
			lower = max(nq + 1, lower);
		}
		else if (!strcmp(answer, "right on"))
		{
			sus |= nq < lower || nq > upper;
			if (sus)
				cout << "Stan is dishonest" << endl;
			else
				cout << "Stan may be honest" << endl;
			return 0;
		}
	}
}