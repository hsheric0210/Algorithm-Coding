/* 중급(上) 2. 정렬과평균구하기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define MAX_LEN 10000

// HELP: 해설 보고 풀음

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n, i;
	fscanf(in, "%d", &n);

	// Input initial numbers
	int* numbers = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		fscanf(in, "%d", numbers + i);

	std::sort(numbers, numbers + n);

	// Average initialization
	double sum = 0;
	for (i = 0; i < n; i++)
		sum += numbers[i];
	double avg = sum / (double)n;

	// dbg
	printf("initial ");
	for (i = 0; i < n; i++)
		printf("%d ", numbers[i]);
	printf("%.0f (%f)\n", avg, avg);

	int resorted = 0;
	while (true)
	{
		int inputNum;
		fscanf(in, "%d", &inputNum);
		
		if (inputNum <= 0)
			break;

		if (inputNum > avg)
		{
			sum -= numbers[0];
			sum += inputNum;
			numbers[0] = inputNum; // replace min
		}
		else if (inputNum < avg)
		{
			sum -= numbers[n - 1];
			sum += inputNum;
			numbers[n - 1] = inputNum; // replace max
		}

		resorted++;
		std::sort(numbers, numbers + n);

		for (i = 0; i < n; i++)
			fprintf(out, "%d ", numbers[i]);
		avg = sum / (double)n;

		//dbg
		printf("Resort %d ", resorted);
		for (i = 0; i < n; i++)
			printf("%d ", numbers[i]);
		printf("%.0f (%f)\n", avg, avg);

		fprintf(out, "%.0f\n", avg);
	}

	fclose(in);
	fclose(out);
	return 0;
}
