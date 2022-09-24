/* 기초 알고리즘(수학) - 6. 주사위 쌓기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int diceCounts = 0;
	fscanf(in, "%d", &diceCounts);
	
	int** dices = (int**)calloc(diceCounts, sizeof(int*));
	for (int i = 0; i < diceCounts; i++)
		dices[i] = (int*)calloc(6, sizeof(int));
	
	for (int i = 0; i < diceCounts; i++)
		for (int j = 0; j < 6; j++)
			fscanf(in, " %d", &dices[i][j]);



	FILE* out = fopen("OUTPUT.TXT", "w");

	fclose(in);
	fclose(out);
	return 0;
}
