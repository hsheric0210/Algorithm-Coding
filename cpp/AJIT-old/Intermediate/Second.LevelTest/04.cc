/* 중급(上) 레벨테스트 4. 카드게임 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define __DEBUG

typedef struct _card
{
	char color;
	int number;
} card;

typedef struct _duplicate
{
	int value;
	int count;
} duplicate;

bool colorcmp(card a, card b)
{
	return a.color > b.color;
}

bool numbercmp(card a, card b)
{
	return a.number > b.number;
}

bool dupcmp(duplicate a, duplicate b)
{
	return a.count > b.count;
}

bool isContinuous(card* cards)
{
	int last = 0;
	for (int i = 0; i < 5; i++)
	{
		if (last > 0 && abs(cards[i].number - last) != 1)
			return false;
		last = cards[i].number;
	}
	return true;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

duplicate* duplicates(card* cards)
{
	duplicate* dup = (duplicate*)calloc(5, sizeof(duplicate));
	if (dup == nullptr)
	{
		printf("[ERR] dup allocation failure");
		return nullptr;
	}
	int dupPos = 0;

	for (int i = 0; i < 5; i++)
	{
		int value = cards[i].number;

		bool incremented = false;
		for (int i = 0; i < dupPos; i++)
		{
			if (dup[i].value == value)
			{
				dup[i].count++;
				incremented = true;
				break;
			}
		}

		if (!incremented)
		{
			dup[dupPos++] = { value, 1 };
		}
	}

	std::sort(dup, dup + 5, dupcmp);

	return dup;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	card cards[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		char color = 0;
		int number = 0;
		fscanf(in, " %c %d", &color, &number);
		cards[i] = { color, number };
	}

	duplicate* dup = duplicates(cards);

	card sortByColor[5] = { 0 };
	card sortByNum[5] = { 0 };

	memcpy(sortByColor, cards, 5 * sizeof(card));
	memcpy(sortByNum, cards, 5 * sizeof(card));

	std::sort(sortByColor, sortByColor + 5, colorcmp);
	std::sort(sortByNum, sortByNum + 5, numbercmp);

	bool continuous = isContinuous(sortByNum);

#ifdef __DEBUG
	for (int i = 0; i < 5; i++)
		printf("[BYCOLOR] (%c, %d)\n", sortByColor[i].color, sortByColor[i].number);

	for (int i = 0; i < 5; i++)
		printf("[BYNUM] (%c, %d)\n", sortByNum[i].color, sortByNum[i].number);

	for (int i = 0; i < 5; i++)
		printf("[DUP] value %d -> %d times\n", dup[i].value, dup[i].count);

	printf("[RESULT] continuous: %d\n", continuous);
#endif

	bool allcolorsame = sortByColor[0].color == sortByColor[4].color;
	int score = 0;

	// #1
	if (allcolorsame && continuous)
		score = sortByNum[0].number + 900;
	
	// #2
	if (dup[0].count == 4)
		score = max(score, dup[0].value + 800);

	// #3
	if (dup[0].count == 3 && dup[1].count == 2)
		score = max(score, dup[0].value * 10 + dup[1].value + 700);

	// #4
	if (allcolorsame)
		score = max(score, sortByNum[0].number + 600);

	// #5
	if (continuous)
		score = max(score, sortByNum[0].number + 500);

	// #6
	if (dup[0].count == 3)
		score = max(score, dup[0].value + 400);

	// #7
	if (dup[0].count == 2 && dup[1].count == 2)
	{
		int d1val = dup[0].value;
		int d2val = dup[1].value;
		score = max(score, max(d1val, d2val) * 10 + min(d1val, d2val) + 300);
	}

	// #8
	if (dup[0].count == 2)
		score = max(score, dup[0].value + 200);

	// #9
	if (score == 0)
		score = sortByNum[0].number + 100;

	fprintf(out, "%d", score);

	free(dup);

	fclose(in);
	fclose(out);
	return 0;
}
