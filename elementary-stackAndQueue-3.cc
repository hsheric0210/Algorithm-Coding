/* 기초 알고리즘(스택 & 큐) - 3. 원형 큐의 구현 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

#define MAX_CMD 10

void printQueue(int* q, int size)
{
	printf(" ");
	for (int i = 0; i < size; i++)
		if (q[i] <= 0)
			printf(" ");
		else
			printf(" %d", q[i]);
}

int main(void)
{
	int capacity = 0;
	printf("Queue size =? ");
	scanf("%d", &capacity);

	int* queue = (int*)calloc(capacity, sizeof(int));
	if (queue == nullptr)
		printf("q arr alloc fail");

	int head = 0;
	int tail = 0;
	int size = 0;

	char* cmd = (char*)calloc(MAX_CMD, sizeof(char));
	if (cmd == nullptr)
		printf("cmd arr alloc fail");

	do {
		scanf("%s", cmd);
		if (!strcmp(cmd, "remove"))
		{
			if (size == 0)
				printf("  Underflow.\n");
			else
			{
				queue[head] = 0;
				head = (head + 1) % capacity;
				size--;
				printQueue(queue, capacity);
				printf("\n");
			}
		}
		else if (!strcmp(cmd, "insert"))
		{
			int num = 0;
			scanf(" %d", &num);

			if (size >= capacity)
				printf("  Overflow.\n");
			else {
				queue[tail] = num;
				tail = (tail + 1) % capacity;
				if (size < capacity) size++;
				printQueue(queue, capacity);
				printf("\n");
			}
		}
	} while (strcmp(cmd, "exit") != 0);
	printf("  Bye.");

	return 0;
}
