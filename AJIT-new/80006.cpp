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
	int min = 1, max = 10, sus = 0;
	int num;
	char buffer[50]{ 0 };
	while (true)
	{
		cin.getline(buffer, 50);
		num = atoi(buffer);
		cin.getline(buffer, 50);
		if (strcmp(buffer, "too high") == 0)
		{
			max = num - 1;
		}
		else if (strcmp(buffer, "too low") == 0)
		{
			min = num + 1;
		}
		else if (strcmp(buffer, "right on") == 0)
		{
			if (num < min || num > max)
				sus = 1;
			break;
		}
		else
		{
			cout << "unknown: " << buffer << endl;
			return 1;
		}
	}
	if (sus)
		cout << "Stan is dishonest" << endl;
	else
		cout << "Stan may be honest" << endl;
	return 0;
}