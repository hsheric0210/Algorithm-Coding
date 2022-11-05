/* 기초 알고리즘(탐색과 정렬) - 5. 힙정렬의구현 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define POP_DEBUG
#define REHEAP_DEBUG
#define REHEAPED_DEBUG

void swap(int* arr, int index1, int index2)
{
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);
	int* tree = (int*)calloc(n + 5, sizeof(int)); // 편의를 위해 배열의 1부터 사용
	for (int i = 1; i <= n; i++)
	{
		fscanf(in, "%d", tree + i); // Insert element at the back of the tree

		int index = i;

		// Heapify
		while (true)
		{
			if (index > 1 && tree[index / 2] < tree[index]) // parent < current
			{
				// swap w/ parent node
				swap(tree, index, index / 2);
				index /= 2; // try it again for the parent
			}
			else
				break; // current = top or parent > current
		}

		// dump tree
		for (int j = 1; j <= i; j++)
			fprintf(out, "%d ", tree[j]);
		fprintf(out, "\n");
	}

	int heapSize = n;
	for (int i = 1; i < n; i++)
	{
		swap(tree, 1, heapSize);
		heapSize--;

#ifdef POP_DEBUG
		printf("heap after pop");
		for (int j = 1; j <= n; j++)
			printf(" %d", tree[j]);
		printf("\n");
#endif

		// re-heapify
		int index = 1;
		while (true)
		{
			int elem = tree[index];
			int leftChild = index * 2 > heapSize ? 0 : tree[index * 2];
			int rightChild = index * 2 + 1 > heapSize ? 0 : tree[index * 2 + 1];
			int swapidx = -1;
			if (elem < leftChild && elem < rightChild)
				swapidx = index * 2 + (leftChild > rightChild ? 0 : 1);
			else if (elem < leftChild)
				swapidx = index * 2;
			else if (elem < rightChild)
				swapidx = index * 2 + 1;

			if (swapidx <= 0 || swapidx > heapSize)
				break;

			swap(tree, index, swapidx);

#ifdef REHEAP_DEBUG
			printf("reheap [%d-%d]", index, swapidx);
			for (int j = 1; j <= n; j++)
				printf(" %d", tree[j]);
			printf("\n");
#endif

			index = swapidx;
		}

		for (int j = 1; j <= n; j++)
			fprintf(out, "%d ", tree[j]);
		fprintf(out, "\n");

	}

	fclose(in);
	fclose(out);
	return 0;
}
