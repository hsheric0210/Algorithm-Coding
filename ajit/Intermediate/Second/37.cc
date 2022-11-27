/* Áß±Þ(ß¾) 37. Undercut */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int rounds;
	fscanf(in, "%d", &rounds);

	int* a_cards = (int*)calloc(rounds, sizeof(int));
	int* b_cards = (int*)calloc(rounds, sizeof(int));
	for (int i = 0; i < rounds; i++)
		fscanf(in, "%d", a_cards + i);
	for (int i = 0; i < rounds; i++)
		fscanf(in, "%d", b_cards + i);

	int a_score = 0, b_score = 0;

	//rounds loop
	for (int round = 0; round < rounds; round++)
	{
		int a_card = a_cards[round];
		int b_card = b_cards[round];
		int delta = abs(a_card - b_card);

		bool undercut = false;
		switch (delta)
		{
		case 0:
			// draw
			break;
		case 1:
		{
			int increment = a_card + b_card;
			if (a_card == 1 || b_card == 1)
			{
				// under cut
				increment = 6;
				undercut = true;
			}
			// useless pointer skills
			*((a_card < b_card) ? &a_score : &b_score) += increment;
			break;
		}
		default:
			if (a_card > b_card)
				a_score += a_card;
			else
				b_score += b_card;
			break;
		}

		printf("round #%d - A=%d B=%d (undercut: %d) delta=%d\n", round, a_card, b_card, undercut, delta);
	}

	fprintf(out, "%d %d", a_score, b_score);
	free(a_cards);
	free(b_cards);

	fclose(in);
	fclose(out);
	return 0;
}
