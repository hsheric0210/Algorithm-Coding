/* 중급(上) 9. 개미의기나긴모험 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FOOD 100
#define MIN_COORD -100
#define MAX_COORD 100

typedef struct _coord {
	int x, y;
} coord;

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = -1, i;
	fscanf(in, "%d", &n);

	coord foods[MAX_FOOD] = {0, 0};

	for (i = 0; i < n; i++)
	{
		int x, y;
		fscanf(in, "%d %d", &x, &y);
		foods[i] = { x, y };
	}

	int distance = 0, x = 0, y = 0;
	for (i = 0; i < n; i++)
	{
		coord crd = foods[i];
		int xDelta = crd.x - x;
		int yDelta = crd.y - y;
		distance += abs(xDelta) + abs(yDelta); // manhattan distance NOTE: Do not use hypot dist in here
		x = crd.x;
		y = crd.y;
	}

	fprintf(out, "%d", distance);

	fclose(in);
	fclose(out);
	return 0;
}
