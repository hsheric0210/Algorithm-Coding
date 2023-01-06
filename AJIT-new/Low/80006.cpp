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
	int min = 1 // 추론 가능한 수의 최솟값
		, max = 10 // 추론 가능한 수의 최댓값
		, sus = 0; // If the imposter is SUS
	int num;
	char buffer[50]{ 0 };
	while (true)
	{
		cin.getline(buffer, 50);
		num = atoi(buffer);
		cin.getline(buffer, 50);
		if (strcmp(buffer, "too high") == 0)
		{
			if (num < min)
				sus = 1;
			max = std::min(num - 1, max);
			if (min > max)
				sus = 1;
		}
		else if (strcmp(buffer, "too low") == 0)
		{
			if (num > max)
				sus = 1;
			min = std::max(min, num + 1);
			if (min > max)
				sus = 1;
		}
		else if (strcmp(buffer, "right on") == 0)
		{
			if (num < min || num > max)
				sus = 1;
			break;
		}
		else
		{
			cout << "unknown answer: " << buffer << endl;
			return 1;
		}
		//cout << "min=" << min << ", max=" << max << ", sus=" << sus << endl;
	}
	if (sus)
		cout << "Stan is dishonest" << endl;
	else
		cout << "Stan may be honest" << endl;
	return 0;
}