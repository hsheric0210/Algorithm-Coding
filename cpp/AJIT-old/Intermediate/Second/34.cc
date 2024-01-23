/* 중급(上) 34. 숫자달팽이 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool checkBoundaryAndSet(int** arr, int n, int xpos, int ypos, int value)
{
	if (xpos < 0 || xpos >= n || ypos < 0 || ypos >= n)
	{
		printf("index overflow caught\n");
		return true;
	}
	arr[ypos][xpos] = value;
	return false;
}

// odd
bool rotateCounterclockwise(int** arr, int n, int& xpos, int& ypos, int dir, int amount, int& counter)
{
	switch (dir % 4)
	{
	case 0:
		for (int x = xpos; x < xpos + amount; x++)
			if (checkBoundaryAndSet(arr, n, x, ypos, counter++))
				return true;
		xpos += amount;
		break;
	case 1:
		for (int y = ypos; y > ypos - amount; y--)
			if (checkBoundaryAndSet(arr, n, xpos, y, counter++))
				return true;
		ypos -= amount;
		break;
	case 2:
		for (int x = xpos; x > xpos - amount; x--)
			if (checkBoundaryAndSet(arr, n, x, ypos, counter++))
				return true;
		xpos -= amount;
		break;
	case 3:
		for (int y = ypos; y < ypos + amount; y++)
			if (checkBoundaryAndSet(arr, n, xpos, y, counter++))
				return true;
		ypos += amount;
		break;
	}

	return false;
}

// even
bool rotateClockwise(int** arr, int n, int& xpos, int& ypos, int dir, int amount, int& counter)
{
	switch (dir % 4)
	{
	case 0:
		for (int y = ypos; y > ypos - amount; y--)
			if (checkBoundaryAndSet(arr, n, xpos, y, counter++))
				return true;
		ypos -= amount;
		break;
	case 1:
		for (int x = xpos; x < xpos + amount; x++)
			if (checkBoundaryAndSet(arr, n, x, ypos, counter++))
				return true;
		xpos += amount;
		break;
	case 2:
		for (int y = ypos; y < ypos + amount; y++)
			if (checkBoundaryAndSet(arr, n, xpos, y, counter++))
				return true;
		ypos += amount;
		break;
	case 3:
		for (int x = xpos; x > xpos - amount; x--)
			if (checkBoundaryAndSet(arr, n, x, ypos, counter++))
				return true;
		xpos -= amount;
		break;
	}

	return false;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);
	bool even = n % 2 == 0;

	int xpos, ypos, counter = 1;
	if (even) // even
	{
		xpos = n / 2 - 1;
		ypos = n / 2;
	}
	else // odd
	{
		xpos = ypos = (n - 1) / 2;
	}

	printf("n = %d\nstart pos (%d, %d)\n", n, xpos, ypos);

	int** arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		arr[i] = (int*)calloc(n, sizeof(int));

	int rotationStage = -1;
	int amount = 1;
	int dir = 0;
	while (xpos < n - 1 || ypos < n - 1)
	{
		if (++rotationStage == 2)
		{
			rotationStage = 0;
			amount++;
		}

		int prevx = xpos, prevy = ypos;
		//arr[ypos][xpos] = counter++;

		// rotate
		if (even)
		{
			if (rotateClockwise(arr, n, xpos, ypos, dir, amount, counter))
				break;
		}
		else
		{
			if (rotateCounterclockwise(arr, n, xpos, ypos, dir, amount, counter))
				break;
		}

		printf("moved from (%d, %d) to (%d, %d) (amount: %d, dir: %d) and set to %d\n", prevx, prevy, xpos, ypos, amount, dir, counter);

		dir++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(out, "%d ", arr[i][j]);
		}
		fprintf(out, "\n");
	}


	fclose(in);
	fclose(out);
	return 0;
}
