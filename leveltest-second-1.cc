/* 중급(上) 레벨테스트 1. 개미의기나긴모험 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int count = 0;
	fscanf(in, "%d", &count);

	int xpos = 0, ypos = 0;
	int dist = 0;
	for (int i = 0; i < count; i++)
	{
		int x = 0, y = 0;
		fscanf(in, "%d %d", &x, &y);
		
		dist += abs(x - xpos) + abs(y - ypos);
		xpos = x;
		ypos = y;
	}

	fprintf(out, "%d", dist);

	fclose(in);
	fclose(out);
	return 0;
}
