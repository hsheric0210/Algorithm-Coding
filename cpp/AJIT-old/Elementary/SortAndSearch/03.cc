/* 기초 알고리즘(탐색과 정렬) - 3. 마법학교 유치원 사물함 번호정하기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

typedef struct kiddo {
	int ordinal;
	int priority;
	int storageID;
} kid;

bool kidcmp(kid a, kid b)
{
	return a.priority < b.priority;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int nkids = 0;
	fscanf(in, "%d", &nkids);
	
	kid* kiddos = (kid*)calloc(nkids, sizeof(kid));
	printf("classes:\t");
	for (int i = 0; i < nkids; i++)
	{
		int clazz = 0;
		fscanf(in, "%d", &clazz);
		kiddos[i] = { i + 1, clazz * nkids + i, 0 };
		printf(" %02d", clazz);
	}
	printf("\n");

	// DBG
	printf("ids:\t\t");
	for (int i = 0; i < nkids; i++)
		printf(" %02d", kiddos[i].ordinal);
	printf("\n");

	printf("priorities:\t");
	for (int i = 0; i < nkids; i++)
		printf(" %02d", kiddos[i].priority);
	printf("\n");
	// DBG

	std::sort(kiddos, kiddos + nkids, kidcmp);

	for (int i = 0; i < nkids; i++)
		kiddos[i].storageID = i + 1;

	for (int i = 0; i < nkids; i++)
	{
		int sid = -1;
		for (int j = 0; j < nkids; j++)
		{
			if (kiddos[j].ordinal == i + 1)
				sid = kiddos[j].storageID;
		}
		fprintf(out, "%d ", sid);
	}

	fclose(in);
	fclose(out);
	return 0;
}
