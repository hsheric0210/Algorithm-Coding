/* 기초 알고리즘(스택 & 큐) - 10. 목걸이 문제 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char in_line[101], line[303], pivot;
	int pos, j, lcount, rcount, m, len, cutStart, cutEnd, maxCount;

	scanf("%s", in_line);
	strcpy(line, in_line);
	strcat(line, in_line);
	strcat(line, in_line);

	len = strlen(in_line);
	m = 2 * len - 1;
	maxCount = 0;

	for (pos = len; pos <= m; pos++) {

		lcount = 0;

		// LEFT Pivot
		pivot = line[pos];

		// LEFT Counter
		// Range: pos until (pos - len)
		// Size: len
		// Direction: Negative
		for (j = pos; j > pos - len; j--) {
			if (line[j] == 'w') lcount++; // If current element is Generic, increment.
			else if (pivot == 'w' && line[j] != 'w') {
				// If pivot is Generic and current element is non-Generic, update pivot and increment.
				pivot = line[j];
				lcount++;
			}
			else if (pivot != 'w' && line[j] == pivot) lcount++; // If pivot is non-Generic and current element == pivot, increment.
			else break; // If pivot is non-Generic and current element != pivot, break.
		}

		rcount = 0;

		// NOTE: '+1' to pivot index and array index is required to skip the last element which has been already processed.

		// RIGHT Pivot
		pivot = line[pos + 1];

		// RIGHT Counter
		// Range: (pos + 1) until (pos + len)
		// Size: len - 1
		// Direction: Positive
		for (j = pos + 1; j < pos + len; j++) {
			if (line[j] == 'w') rcount++;
			else if (pivot == 'w' && line[j] != 'w') {
				pivot = line[j];
				rcount++;
			}
			else if (pivot != 'w' && line[j] == pivot) rcount++;
			else break;
		}

		if (maxCount < lcount + rcount) {
			maxCount = lcount + rcount;
			cutStart = pos + 1 - len;
		}

		if (maxCount > len) maxCount = len;
	}

	if (cutStart < len) cutEnd = cutStart + 1;
	else cutEnd = 1;

	printf("%d %d %d", maxCount, cutStart, cutEnd);

	return 0;
}