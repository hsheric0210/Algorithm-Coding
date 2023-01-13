/* 기초 알고리즘(스택 & 큐) - 6. 괄호 맞추기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stack>

#define MAX_PARENTHESES 50

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	std::stack<int> parentheses;
	char ch;
	int index = 0;
	int* priority = (int*)calloc(MAX_PARENTHESES, sizeof(int));
	if (priority == nullptr)
	{
		printf("priority arr alloc fail");
		fclose(in);
		return 1;
	}

	FILE* out = fopen("OUTPUT.TXT", "w");
	int priorityCounter = 1;
	while ((ch = fgetc(in)) != EOF)
	{
		if (ch != '(' && ch != ')') continue;

		if (ch == '(')
		{
			parentheses.push(index);
		}
		else
		{
			if (parentheses.empty())
			{
				fprintf(out, "WRONG EXPRESSION");
				fclose(in);
				fclose(out);
				return 0;
			}

			priority[parentheses.top()] = priorityCounter;
			priority[index] = priorityCounter;
			parentheses.pop();
			priorityCounter++;
		}

		index++;
	}

	if (parentheses.empty())
	{
		for (int i = 0; i < index; i++)
		{
			fprintf(out, "%d ", priority[i]);
		}
	}
	else
		fprintf(out, "WRONG EXPRESSION");

	fclose(in);
	fclose(out);
	return 0;
}
