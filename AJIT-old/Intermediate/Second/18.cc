/* 중급(上) 18. clock */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define min(x, y) (((x) >= (y)) ? (y) : (x))

typedef struct _time {
	int hour, minute;
	double delta;
} time;

bool cmp(time first, time second)
{
	return first.delta < second.delta;
}

// 시침: 시간당 30º 분당 0.5º
// 분침: 분당 6º
// -> 시침-분침: 시간 * 30.0 + 분 * 0.5 - 분 * 6.0
// -> 시간 * 30.0 - 분 * 5.5

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	time times[5] = { 0 };

	int i;
	for (i = 0; i < 5; i++)
	{
		int h = 0, m = 0;
		fscanf(in, "%d:%d", &h, &m);
		int filteredH = h;
		if (filteredH >= 12)
			filteredH -= 12;
		double delta = fabs(filteredH * 30.0 - m * 5.5);
		double filteredDelta = delta;
		while (filteredDelta > 180.0)
			filteredDelta = 360.0 - filteredDelta;
		printf("time %d (%02d:%02d, %02d:%02d) delta: %.6f corrected %.06f\n", i, h, m, filteredH, m, delta, filteredDelta);
		times[i] = { h, m, filteredDelta };
	}

	std::stable_sort(times, times + 5, cmp);

	for (i = 0; i < 5; i++)
	{
		printf("times[%d] = '%02d:%02d' (delta %.6f)\n", i, times[i].hour, times[i].minute, times[i].delta);
	}

	fprintf(out, "%02d:%02d", times[2].hour, times[2].minute);

	fclose(in);
	fclose(out);
	return 0;
}
