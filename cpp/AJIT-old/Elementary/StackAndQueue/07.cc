/* 기초 알고리즘(스택 & 큐) - 7. 책정리 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>
#include <stack>

#define MAX_PARENTHESES 50
#define DUMP_STACK(ticks, stackA, stackB) do { 													  \
printf("[#%d] A:", ticks);																		  \
for (auto itr = a._Get_container().cbegin(); itr != a._Get_container().cend(); itr++)			  \
{																								  \
	printf(" %c", *itr);																		  \
}																								  \
printf("\n");																					  \
printf("[#%d] B:", ticks);																		  \
for (auto itr = b._Get_container().cbegin(); itr != b._Get_container().cend(); itr++)			  \
{																								  \
	printf(" %c", *itr);																		  \
}																								  \
printf("\n");																					  \
} while(false);																								  \

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int bookCount = 0;
	fscanf(in, "%d", &bookCount);

	std::stack<char> a;
	std::stack<char> b;
	for (int i = 0; i < bookCount; i++)
	{
		char ch;
		fscanf(in, " %c", &ch);
		printf("A[%d]=%c\n", i, ch);
		a.push(ch);
	}

	std::deque<char> target;
	for (int i = 0; i < bookCount; i++)
	{
		char ch;
		fscanf(in, " %c", &ch);
		printf("Target[%d]=%c\n", i, ch);
		target.push_back(ch);
	}

	int ticks = 0;
	for (; !target.empty(); ticks++)
	{
		DUMP_STACK(ticks, a, b);

		char currentTarget = target.front();
		bool haveTarget = false;
		if (!a.empty())
		{
			for (auto itr = a._Get_container().begin(); itr != a._Get_container().end(); itr++)
			{
				if (*itr == currentTarget)
				{
					haveTarget = true;
					break;
				}
			}
		}

		if (haveTarget)
		{
			char atop = a.top();
			if (atop == currentTarget)
			{
				printf("[#%d] EQ '%c'\n", ticks, currentTarget);
				target.pop_front(); // matches
				a.pop();
			}
			else
			{
				b.push(atop); // move to B
				printf("[#%d] NEQ (ATop)'%c' != (CurrentTarget)'%c'\n", ticks, atop, currentTarget);
				a.pop();
			}
		}
		else
		{
			if (b.empty())
				printf("warn: a not contains target and b is empty\n");
			// refill A with B
			printf("[#%d] Stack-A doesn't have target '%c'\n", ticks, currentTarget);
			char btop = b.top();
			a.push(btop);
			b.pop();
			printf("[#%d] Moving '%c' from B to A\n", ticks, btop);
		}
	}

	FILE* out = fopen("OUTPUT.TXT", "w");
	fprintf(out, "%d", ticks);
	fclose(in);
	fclose(out);
	return 0;
}
