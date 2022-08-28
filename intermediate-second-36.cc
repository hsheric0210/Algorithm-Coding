/* 중급(上) 36. 카드게임 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

typedef struct _card {
	char color;
	int number;
} card;

typedef struct _duplicate {
	int count, value, index;
} duplicate;

bool colorComparator(card a, card b)
{
	return a.color < b.color;
}

bool numberComparator(card a, card b)
{
	return a.number > b.number;
}

bool duplicateComparator(duplicate a, duplicate b)
{
	return a.count > b.count;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

/// <summary>
/// 카드의 숫자가 연속적으로 배치되어 있는지를 검사
/// </summary>
/// <param name="cards">숫자 순서로 오름차순 또는 내림차순 정렬된 카드들의 배열</param>
/// <returns>카드의 숫자들이 연속적으로 배열되어 있는지의 여부</returns>
bool isContinuous(card* cards)
{
	int prev = -1;
	for (int i = 0; i < 5; i++)
	{
		if (prev > 0 && abs(prev - cards[i].number) != 1)
			return false;
		prev = cards[i].number;
	}
	return true;
}

duplicate *countDuplicate(card* cards)
{
	// duplicate count[9] = { {0,0,0} }; - stack freed after the return
	duplicate* count = (duplicate*)calloc(9, sizeof(duplicate));
	int lookup[9] = { 0 };
	int lookupIndex = 0;
	for (int i = 0; i < 5; i++)
	{
		card c = cards[i];

		int index = -1;
		// find lookup
		if (lookupIndex > 0)
			for (int j = 0; j < 9; j++)
				if (lookup[j] == c.number)
				{
					index = j;
					break;
				}
		// lookup not found
		if (index == -1)
			lookup[index = lookupIndex++] = c.number;

		count[index] = { count[index].count + 1, lookup[index], index};
	}

	std::sort(count, count + 9, duplicateComparator);
	return count;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	card cards[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		char color;
		int number;
		fscanf(in, " %c %d", &color, &number);
		cards[i] = { color,number };
	}

	card sortByColor[5] = { 0 };
	card sortByNumber[5] = { 0 };
	memcpy(sortByColor, cards, 5 * sizeof(card));
	memcpy(sortByNumber, cards, 5 * sizeof(card));
	std::sort(sortByColor, sortByColor + 5, colorComparator);
	std::sort(sortByNumber, sortByNumber + 5, numberComparator);

	int score = 0;

	bool continuous = isContinuous(sortByNumber);
	duplicate* dup = countDuplicate(sortByNumber);

	for (int i = 0; i < 9; i++)
	{
		printf("duplicate[%d] = '%d' -> %d times\n", i, dup[i].value, dup[i].count);
	}

	// DEBUG PRINT REMOVE BEFORE SUBMIT
	printf("continuous: %d\n", continuous);
	for (int i = 0; i < 5; i++)
		printf("sortByColor[%d] = %c %d\n", i, sortByColor[i].color, sortByColor[i].number);

	for (int i = 0; i < 5; i++)
		printf("sortByNumber[%d] = %c %d\n", i, sortByNumber[i].color, sortByNumber[i].number);
	// DEBUG PRINT REMOVE BEFORE SUBMIT

	// 5장 동일 색상 & 연속 숫자
	if (sortByColor[0].color == sortByColor[4].color && continuous)
	{
		score = max(sortByNumber[0].number + 900, score);
	}

	// 4장 동일 숫자
	if (dup[0].count == 4)
		score = max(dup[0].value + 800, score);

	// 3-2 숫자 동일
	if (dup[0].count == 3 && dup[1].count == 2)
		score = max(dup[0].value * 10 + dup[1].value + 700, score);

	// 5장 동일 색상
	if (sortByColor[0].color == sortByColor[4].color)
		score = max(sortByNumber[0].number + 600, score);

	// 연속 숫자
	if (continuous)
		score = max(sortByNumber[0].number + 500, score);

	// 3장 숫자 동일
	if (dup[0].count == 3)
		score = max(dup[0].value + 400, score);

	// 2-2 숫자 동일
	if (dup[0].count == 2 && dup[1].count == 2)
		score = max(max(dup[0].value, dup[1].value) * 10 + min(dup[0].value, dup[1].value) + 300, score);

	// 2장 숫자 동일
	if (dup[0].count == 2)
		score = max(dup[0].value + 200, score);

	if (score <= 0)
		score = sortByNumber[0].number + 100;

	fprintf(out, "%d", score);

	free(dup);

	fclose(in);
	fclose(out);
	return 0;
}
