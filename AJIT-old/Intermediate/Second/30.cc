/* Áß±Þ(ß¾) 30. Worm Turns */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <deque>

typedef struct _pos {
	int x, y;

	struct _pos add(struct _pos offset)
	{
		return { x + offset.x, y + offset.y };
	}

	bool equals(struct _pos other)
	{
		return x == other.x && y == other.y;
	}

	char* tostr()
	{
		char* buffer = (char*)calloc(30, sizeof(char));
		sprintf(buffer, "(%d, %d)", x, y);
		return buffer;
	}
} pos;

void debugPrintPositions(std::deque<pos> snake, pos newHeadPos)
{
#ifdef DEBUG_PRINT
	int i, j;
	char arr[50][50] = { 0 };
	for (auto p = snake.cbegin(); p != snake.cend(); p++)
	{
		if (p == snake.cbegin())
			arr[p->x - 1][p->y - 1] = 'H';
		else if (p == snake.cend() - 1)
			arr[p->x - 1][p->y - 1] = 'T';
		else
			arr[p->x - 1][p->y - 1] = '=';
	}
	arr[newHeadPos.x - 1][newHeadPos.y - 1] = 'h';

	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			char ch = arr[i][j];
			if (ch == 0)
				ch = '-';
			printf("%c", ch);
		}
		printf("\n");
	}
#endif
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int moves = 0;
	fscanf(in, "%d", &moves);

	int i, continueLoop = 1;
	pos previousHeadPos = { 25, 30 };
	pos previousTailPos = { 25, 11 };

	// HEAD: snake head, TAIL: snake tail
	std::deque<pos> snake;
	for (i = 11; i <= 30; i++)
		snake.push_front({ 25, i });

	fgetc(in); //strip space or newline

	for (i = 0; (i < moves) && continueLoop; i++)
	{
		pos offset;
		char action = fgetc(in);
		switch (action)
		{
		case 'N':
			offset = { -1, 0 };
			break;
		case 'S':
			offset = { 1, 0 };
			break;
		case 'E':
			offset = { 0, 1 };
			break;
		case 'W':
			offset = { 0, -1 };
			break;
		default:
			offset = { 0, 0 };
			printf("[ERROR] Undefined action: '%c'\n", action);
			break;
		}

		previousHeadPos = previousHeadPos.add(offset);
		char* offsetStr = offset.tostr();
		char* prevStr = previousHeadPos.tostr();
		printf("[Movement] #%d - %c - Offset %s dest %s\n", i + 1, action, offsetStr, prevStr);
		free(offsetStr);

		// check border
		if (previousHeadPos.x <= 0 || previousHeadPos.y <= 0 || previousHeadPos.x > 50 || previousHeadPos.y > 50)
		{
			fprintf(out, "%d out", i + 1);
			continueLoop = 0;
			break;
		}

		printf("--- MOVE #%d\n", i + 1);
		debugPrintPositions(snake, previousHeadPos);

		// check collision
		for (auto j = snake.cbegin(); j != snake.cend(); j++)
		{
			if (((pos)(*j)).equals(previousHeadPos))
			{
				char* snakeStr = ((pos)(*j)).tostr();
				printf("[COLLISION] New head position %s collides with bodies %s\n", prevStr, snakeStr);
				free(snakeStr);
				fprintf(out, "%d itself", i + 1);
				continueLoop = 0;
			}
		}
		free(prevStr);

		// push new head pos
		snake.push_front(previousHeadPos);

		// pop last tail pos
		snake.pop_back();
	}

	if (continueLoop)
	{
		fprintf(out, "%d success", i);
	}


	fclose(in);
	fclose(out);
	return 0;
}
