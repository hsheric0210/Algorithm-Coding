/* 기초 알고리즘(스택 & 큐) - 8. Car Racing */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <deque>
#include <algorithm>

#define MAX_PARENTHESES 50

#define DUMPQ(name, q) do { 													  \
printf("%s:", name);																		  \
for (auto itr = q.cbegin(); itr != q.cend(); itr++)			  \
{																								  \
	printf(" %d", *itr);																		  \
}																								  \
printf("\n");																		  \
} while(false);	

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int carCount = 0;
	fscanf(in, "%d", &carCount);

	std::deque<int> entrance;
	for (int i = 0; i < carCount; i++)
	{
		int carID = 0;
		fscanf(in, " %d", &carID);
		entrance.push_back(carID);
	}


	std::deque<int> targetCars(entrance);
	std::sort(targetCars.begin(), targetCars.end());

	FILE* out = fopen("OUTPUT.TXT", "w");

	std::deque<int> bypassLine;

	bool avail = true;
	while(!targetCars.empty())
	{
		int target = targetCars.front();
		if (!entrance.empty() && entrance.front() == target)
		{
			// Entrance -> Start line
			targetCars.pop_front();
			printf("#%d e -> sl\n", target);
			entrance.pop_front();
		}
		else if (!bypassLine.empty() && bypassLine.front() == target)
		{
			// Bypass line -> Start line
			targetCars.pop_front();
			printf("bypop #%d -> sl\n", target);
			bypassLine.pop_front();
		}
		else if (!entrance.empty())
		{
			// Push to bypass line
			bypassLine.push_back(entrance.front());
			printf("#%d -> by\n", entrance.front());
			entrance.pop_front();
		}
		else
		{
			// Entrance empty and bypassline front NEQ
			avail = targetCars.empty();
			break;
		}
	}

	if (avail)
		fprintf(out, "YES");
	else
		fprintf(out, "NO");

	fclose(in);
	fclose(out);
	return 0;
}
