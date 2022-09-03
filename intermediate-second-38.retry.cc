/* 중급(上) 38. 긴자리수의곱셈 */
/* 해설 참고 후 재시도한 버전 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 250

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char* first = (char*)calloc(MAX_LENGTH, sizeof(char));
	char* second = (char*)calloc(MAX_LENGTH, sizeof(char));

	// Read numbers
	fgets(first, MAX_LENGTH, in);
	fgets(second, MAX_LENGTH, in);

	int _first[205] = { 0 };
	int _second[205] = { 0 };
	int result[405] = { 0 };
	bool checkRequired[405] = { true };

	int first_len = strlen(first) - 1;
	int second_len = strlen(second);

	for (int i = 0; i < first_len; i++)
		_first[first_len - i - 1] = first[i] - '0';
	for (int i = 0; i < second_len; i++)
		_second[second_len - i - 1] = second[i] - '0';

	for (int i = 0; i < first_len; i++)
	{
		for (int j = 0; j < second_len; j++)
		{
			result[i + j] += _first[i] * _second[j];
			checkRequired[i + j] = true;
		}
	}

	int index = 0;
	while (true)
	{
		if (!checkRequired[index])
			break;

		if (result[index] >= 10)
		{
			result[index + 1] += result[index] / 10;
			result[index] %= 10;
			checkRequired[index + 1] |= true;
		}
		index++;
	} 

	bool start = false;
	for (int i = 0; i < index; i++)
	{
		if (result[index - i - 1] != 0)
			start = true;
		if (start)
			fprintf(out, "%d", result[index - i - 1]);
	}
	
	if (!start)
		fprintf(out, "0");

	fclose(in);
	fclose(out);
	return 0;
}
