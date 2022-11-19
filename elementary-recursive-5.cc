/* 기초 알고리즘(재귀호출) - 5. 하노이탑 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <array>
#include <optional>
#include <algorithm>

#undef DBGPRINT
#define STR_LEN 10000000

std::stack<int> a;
std::stack<int> b;
std::stack<int> c;

char* moves;

std::stack<int> *indexStack(int index)
{
	switch (index)
	{
	case 0:
		return &a;
	case 1:
		return &b;
	case 2:
		return &c;
	}
}

char indexStackChar(int index)
{
	switch (index)
	{
	case 0:
		return 'A';
	case 1:
		return 'B';
	default:
		return 'C';
	}
}

#ifdef DBGPRINT
void dumpStackContents(int stack)
{
	auto container = indexStack(stack) -> _Get_container();
	printf("Container %c data:", indexStackChar(stack));
	for (auto a = container.begin(); a != container.end(); a++)
		printf(" %d", *a);
	printf("\n");
}
#endif

void move(int firstStack, int secondStack)
{
#ifdef DBGPRINT
	printf("PRE\n");
	dumpStackContents(0);
	dumpStackContents(1);
	dumpStackContents(2);

	printf("%c -> %c\n", indexStackChar(firstStack), indexStackChar(secondStack));
#endif

	char* sbuf = (char*)calloc(15, sizeof(char));
	sprintf(sbuf, "%c %c\n", indexStackChar(firstStack), indexStackChar(secondStack));
	strcat(moves, sbuf);
	free(sbuf);

	indexStack(secondStack) -> push(indexStack(firstStack) -> top());
	indexStack(firstStack) -> pop();

#ifdef DBGPRINT
	printf("POST\n");
	dumpStackContents(0);
	dumpStackContents(1);
	dumpStackContents(2);
#endif
}

int* swap(int _index[], int firstIndex, int secondIndex)
{
	// yeah, i'll going to ignore the memory leakage.
	int* index = (int*)malloc(3 * sizeof(int));
	memcpy(index, _index, 3 * sizeof(int));

	int tmp = index[firstIndex];
	index[firstIndex] = index[secondIndex];
	index[secondIndex] = tmp;

	return index;
}

int hanoi(int n, int _index[])
{
	int* index = (int*)malloc(3 * sizeof(int));
	memcpy(index, _index, 3 * sizeof(int));
	if (n == 1)
	{
		move(index[0], index[2]); // A -> C
		return 1;
	}
	
	if (n == 2)
	{
		move(index[0], index[1]);
		move(index[0], index[2]);
		move(index[1], index[2]);
		return 3;
	}
	
	int count = 1;
	count += hanoi(n - 1, swap(index, 1, 2)); // swap buffer and destination
	move(index[0], index[2]); // move source to buffer
	count += hanoi(n - 1, swap(index, 0, 1)); // swap source and buffer
	free(index);
	return count;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	int n = 0;
	fscanf(in, "%d", &n);
	fclose(in);

	for (int i = n - 1 ; i >= 0; i--)
		a.push(i + 1);

	int avail = pow(2, n) * 4 + 100;
	moves = (char*)calloc(avail, sizeof(char));

	FILE* out = fopen("OUTPUT.TXT", "w");
	int index[3] = { 0, 1, 2 };
	fprintf(out, "%d\n", hanoi(n, index));
	fprintf(out, "%s", moves);

	fclose(out);
	return 0;
}
