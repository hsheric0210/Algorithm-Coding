/* 중급(上) 2. 정렬과평균구하기 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <algorithm>

#define MAX_LEN 10000

int main(void) {
	FILE* in = fopen("INPUT.TXT", "r");

	FILE* out = fopen("OUTPUT.TXT", "w");

	int n, i; fscanf(in, "%d", &n); // Input initial numbers

	int* numbers = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)

		fscanf(in, "%d", numbers + i);

	std::sort(numbers, numbers + n); // Average initialization

	int sum = 0;

	for (i = 0; i < n; i++)

		sum += numbers[i];

	double avg = sum / (double)n; // dbg

	while (true) {
		int inputNum;

		fscanf(in, "%d", &inputNum);

		if (inputNum == 0) break;

		if (inputNum > (int)avg) {
			sum -= numbers[0];

			sum += inputNum;

			numbers[0] = inputNum; // replace min
		}

		else {
			sum -= numbers[n - 1];

			sum += inputNum;

			numbers[n - 1] = inputNum; // replace max
		}

		std::sort(numbers, numbers + n);

		for (i = 0; i < n; i++)

			fprintf(out, "%d ", numbers[i]);

		avg = sum / (double)n;

		fprintf(out, "%.0lf\n", avg);
	}

	fclose(in);

	fclose(out);

	return 0;
}