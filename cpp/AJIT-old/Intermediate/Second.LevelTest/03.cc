/* 중급(上) 레벨테스트 3. 달팽이안의문자 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 500

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int m = 0, n = 0, xget = 0, yget = 0;
	fscanf(in, "%d %d %d %d", &m, &n, &xget, &yget);

	int** arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		arr[i] = (int*)calloc(n, sizeof(int));
	if (arr == nullptr)
	{
		printf("[ERR] array allocation failure");
		return 1;
	}

	int xpos = 0, ypos = 0, counter = m, direction = 0;
	bool collided = false;
	while (true)
	{
		int newx = xpos;
		int newy = ypos;
		switch (direction)
		{
		case 0:
			newx++;
			break;
		case 1:
			newy++;
			break;
		case 2:
			newx--;
			break;
		case 3:
			newy--;
			break;
		}

		bool prev_collided = collided;
		// if collided
		collided = newx < 0 || newx >= n || newy < 0 || newy >= n || arr[newx][newy] != 0;

		if (prev_collided && collided) // if collided again (changed direction but colllision is not fixed)
		{
			arr[xpos][ypos] = counter++;
			printf("re-collided at pos x %d y %d new x %d y %d\n", xpos, ypos, newx, newy);
			break;
		}

		if (collided)
		{
			// increment direction and retry
			direction = (direction + 1) % 4;
		}
		else
		{
			// update pos
			arr[xpos][ypos] = counter++;
			xpos = newx;
			ypos = newy;
		}
	}

#ifdef DUMP
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
#endif

	fprintf(out, "%d", arr[yget - 1][xget - 1]);


	fclose(in);
	fclose(out);
	return 0;
}
