/* 중급(上) 33. 비밀번호 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);

	int* passwords = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%d", passwords + i);
	}

	int input = 0;
	fscanf(in, "%d", &input);
	bool matches = false;

	for (int i = 0; i < n; i++)
	{
		int divisor = 1;

		bool match = true;
		bool specialMatch = true;

		bool specialChance = true;

		for (int j = 0; j < 5; j++)
		{
			int numAt = input / divisor % 10;
			int pwNumAt = passwords[i] / divisor % 10;

			printf("[Worker #%d] Password index %d - Correct: %d Pressed: %d\n", i, j, pwNumAt, numAt);

			match &= numAt == pwNumAt;

			if (!match && specialChance)
			{
				// use chance (allow adjacent button press)
				if (numAt == 0)
					numAt = 11;

				int candidates[4] = { pwNumAt - 1, pwNumAt + 1, pwNumAt - 3, pwNumAt + 3 };
				for (int k = 0; k < 4; k++)
				{
					if (numAt == candidates[k])
					{
						printf("[Worker #%d] Used the special chance (pressed not correct but adjacent button).\n", i);
						specialChance = false;
						match = true;
						break;
					}
				}
			}

			if (!match)
			{
				printf("[Worker #%d] Failed due to unmatch more than two times in a row.\n", i);
				break;
			}

			divisor *= 10;
		}

		matches |= match;
	}

	if (matches)
		fprintf(out, "OPEN");
	else
		fprintf(out, "CLOSE");

	fclose(in);
	fclose(out);
	return 0;
}
