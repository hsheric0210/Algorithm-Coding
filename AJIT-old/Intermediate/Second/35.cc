/* 중급(上) 35. 알파벳피라미드 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	char ch = 'A';
	fscanf(in, "%c", &ch);
	int index = ch - 'A' - 1;

	int n = 0;
	fscanf(in, "%d", &n);

	if (ch < 'A' || ch > 'Z' || n < 0 || n > 24)
	{
		fprintf(out, "입력에러!");
		return 1;
	}

	// even index: backward loop
	// odd index: forward loop

	for (int i = 0; i < n; i++)
	{
		// draw blanks
		for (int j = 0; j < n - i - 1; j++)
			fprintf(out, " ");

		bool even = i % 2 == 0;
		int elemCount = i * 2 + 1;

		if (even)
		{
			// backward loop
			for (int i = elemCount; i > 0; i--)
			{
				printf("back: %d(%c)\n", index + i, (index + i) % 26 + 'A');
				fprintf(out, "%c", (index + i) % 26 + 'A');
			}
			index += elemCount + 1;
		}
		else
		{
			// forward loop
			for (int i = 0; i < elemCount ; i++)
			{
				printf("for: %d(%c)\n", index + i, (index + i) % 26 + 'A');
				fprintf(out, "%c", (index + i) % 26 + 'A');
			}
			index += elemCount - 1;
		}

		// draw newline
		fprintf(out, "\n");
	}


	fclose(in);
	fclose(out);
	return 0;
}
