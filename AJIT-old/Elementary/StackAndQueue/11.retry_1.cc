/* 기초 알고리즘(스택 & 큐) - 10. 목걸이 문제 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char in_line[101], line[303], pivot;
	int pos, j, lcount, rcount, posEnd, len, cutStart, cutEnd, maxCount;

	scanf("%s", in_line);
	strcpy(line, in_line);
	strcat(line, in_line);
	strcat(line, in_line);

	len = strlen(in_line);
	posEnd = 2 * len - 1;
	maxCount = 0;

	for (pos = len; pos <= posEnd; pos++) {

		lcount = 0;
		pivot = line[pos];

		for (j = 0; j > -len; j--) {
			int index = pos - j;
			if (line[index] == 'w') lcount++;
			else if (pivot == 'w' && line[index] != 'w') {

				pivot = line[index];
				lcount++;

			}
			else if (pivot != 'w' && line[index] == pivot) lcount++;
			else break;
		}

		rcount = 0;
		pivot = line[pos + 1];

		for (j = 1; j < len; j++) {
			int index = pos + j;
			if (line[index] == 'w') rcount++;
			else if (pivot == 'w' && line[index] != 'w') {

				pivot = line[index];
				rcount++;
			}
			else if (pivot != 'w' && line[index] == pivot) rcount++;
			else break;
		}

		if (maxCount < lcount + rcount) {
			maxCount = lcount + rcount;
			cutStart = pos + 1 - len; // '+1' required because the index is zero-based
		}

		if (maxCount > len) maxCount = len;
	}

	if (cutStart < len) cutEnd = cutStart + 1;
	else cutEnd = 1;

	printf("%d %d %d", maxCount, cutStart, cutEnd);

	return 0;
}