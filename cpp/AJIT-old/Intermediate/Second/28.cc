/* 중급(上) 28. 수뒤집기*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 100

int reverseNum(int num)
{
	char* buffer = (char*)calloc(MAX_BUFFER, sizeof(char));
	if (buffer == nullptr) // failed to allocate
		return 0;
	_itoa(num, buffer, 10);
	_strrev(buffer);
	return atoi(buffer);
}

int compareSides(int num)
{
	char* buffer = (char*)calloc(MAX_BUFFER, sizeof(char));
	_itoa(num, buffer, 10);
	int len = strlen(buffer);

	int i, mirrored = 1;
	//even
	if (len % 2 == 0)
	{
		// example: 6
		// 0, 1, 2 vs 5, 4, 3
		for (i = 0; i < len / 2; i++)
		{
			printf("[EVEN] comparing [%d]%d vs [%d]%d\n", i, buffer[i], len - i, buffer[len - i - 1]);
			if (buffer[i] != buffer[len - i - 1])
			{
				mirrored = 0;
				break;
			}
		}
	}
	else // odd
	{
		// example: 7
		// (omit 3) 0, 1, 2 vs 4, 5, 6
		for (i = 0; i < (len - 1) / 2; i++)
		{
			printf("[ODD] comparing [%d]%d vs [%d]%d\n", i, buffer[i], len - i, buffer[len - i - 1]);
			if (buffer[i] != buffer[len - i - 1])
			{
				mirrored = 0;
				break;
			}
		}
	}

	return mirrored;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0, len = 0;
	fscanf(in, "%d", &n);
	int reversed = reverseNum(n);
	printf("reversed num: %d, length: %d, sum: %d\n", reversed, len, n + reversed);
	if (compareSides(n + reversed))
		fputs("YES", out);
	else
		fputs("NO", out);

	fclose(in);
	fclose(out);
	return 0;
}
