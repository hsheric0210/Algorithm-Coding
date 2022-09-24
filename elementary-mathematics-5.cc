/* 기초 알고리즘(수학) - 5. 문자열 압축 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>

#define MAX_LENGTH 200
#define I_MAX_LENGTH 50

char* intToStr(int value)
{
	char* str = (char*)calloc(I_MAX_LENGTH, sizeof(char));
	if (str == nullptr)
	{
		printf("intToStr: compressed string array allocation failure.\n");
		return nullptr;
	}

	_itoa(value, str, 10);

	return str;
}

int intCharArrToStr(int len, char* arr)
{
	int value = 0;
	for (int i = 0; i < len; i++)
	{
		char ch = arr[i];
		if (!isdigit(ch))
		{
			return -1;
		}
		printf("intCharArrToStr: [%d] = %c (%d)\n", i, ch, ch);
		value += (ch - '0') * (int)pow(10, len - i - 1);
	}
	return value;
}

char* uncompress(int len, char* compressed, int* contentLen)
{
	char* content = (char*)calloc(MAX_LENGTH, sizeof(char));
	int clen = 0;
	if (content == nullptr)
	{
		printf("uncompress: content string array allocation failure.\n");
		return nullptr;
	}

	printf("uncompress: string '%s'\n", compressed);

	for (int i = 0; i < len; i++)
	{
		char ch = compressed[i];

		if (ch == '(' && i + 1 <= len - 1 /*check index boundary*/ && isdigit(compressed[i + 1])) // quickly determine if it is RLE compression part
		{
			printf("uncompress: detected possible RLE compression part at index %d\n", i);
			// find the matching closing parenthese
			int numberEnd = -1;
			for (int j = i + 2; j < len; j++)
			{
				if (compressed[j] == ')')
				{
					numberEnd = j - 1;
					break;
				}
			}
			printf("uncompress: found matching closing parenthese at index %d\n", numberEnd + 1);

			if (numberEnd < i + 1 && numberEnd + 2 <= len - 1) // check invalid bound
			{
				content[clen++] = ch;
				//skipped
			}
			else
			{
				//parse RLE compression
				int repetition = intCharArrToStr(numberEnd - i, compressed + (i + 1));
				if (repetition < 0)
				{
					// invalid char included
					content[clen++] = ch;
					//skipped
				}
				else
				{
					printf("uncompress: detected obvious RLE compression part at index %d: char '%c' x %d times.\n", i, compressed[numberEnd + 2], repetition);
					for (int j = 0; j < repetition; j++)
					{
						content[j + clen] = compressed[numberEnd + 2];
					}
					clen += repetition;
					i += (numberEnd - i) + 2;
				}
			}
		}
		else
			content[clen++] = ch;
	}

	*contentLen = clen;
	return content;
}

char* compress(int len, char* content, int* compressedLen)
{
	char* compressed = (char*)calloc(MAX_LENGTH, sizeof(char));
	if (compressed == nullptr)
	{
		printf("compress: compressed string array allocation failure.\n");
		return nullptr;
	}

	printf("compress: compressing '%s'\n", content);

	int clen = 0;

	char last = '\0';

	int repetitionTime = 0;
	for (int i = 0; i <= len; i++)
	{
		char ch = content[i];

		if (ch == last && ch != '\0')
		{
			repetitionTime++;
		}
		else
		{
			if (repetitionTime > 0)
			{
				if (repetitionTime <= 2)
				{
					// don't compress
					for (int i = 0; i <= repetitionTime; i++)
					{
						compressed[clen + i] = last;
					}
					clen += repetitionTime + 1;
				}
				else
				{
					// RLE compress
					compressed[clen++] = '(';

					char* count = intToStr(repetitionTime + 1);
					int len = strlen(count);
					for (int j = 0; j < len; j++)
						compressed[clen + j] = count[j];
					clen += len;

					compressed[clen++] = ')';
					compressed[clen++] = last;
				}
				printf("compress: char '%c' repeated '%d' times.\n", last, repetitionTime + 1);
			}
			if (!(i + 1 <= len - 1 && ch == content[i + 1])) // check possible dup
				compressed[clen++] = ch;
			repetitionTime = 0;
		}

		last = ch;
	}

	*compressedLen = clen;
	return compressed;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	char* content = (char*)calloc(MAX_LENGTH, sizeof(char));
	if (content == nullptr)
	{
		printf("content array allocation failure.\n");
		fclose(in);
		return 1;
	}

	bool shouldCompress = fgetc(in) != 'U';
	fgetc(in); // Drop newline

	fgets(content, MAX_LENGTH, in);
	int contentLen = strlen(content);
	printf("input: '%s' (len=%d)\n", content, contentLen);

	FILE* out = fopen("OUTPUT.TXT", "w");

	int compLen = 0;
	char* comp = (shouldCompress ? compress : uncompress)(contentLen, content, &compLen);
	fputs(comp, out);
	free(comp);

	fclose(in);
	fclose(out);
	free(content);
	return 0;
}
