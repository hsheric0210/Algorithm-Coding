/* 기초 알고리즘(스택 & 큐) - 10. 목걸이 문제 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <deque>

#define DBGPRINT
#define MAX_LEN 105

int main(void)
{
	char* line = (char*)calloc(MAX_LEN, sizeof(char));
	if (line == nullptr)
	{
		printf("warn: line alloc fail.\n");
		return 1;
	}

	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");
	fgets(line, MAX_LEN, in);
	fclose(in);

	int len = strlen(line);

	int maxlen = 0, maxoff = 0;
	for (int cutPoint = 0; cutPoint < len - 1; cutPoint++)
	{
		std::deque<char> left;
		std::deque<char> right;

		char lp = 0, rp = 0;
#ifdef DBGPRINT
		printf("[LEFT@%d] ", cutPoint);
#endif
		for (int il = 0; il <= cutPoint; il++)
		{
			left.push_back(line[il]);
			if (lp == 0 && (line[il] == 'r' || line[il] == 'b'))
				lp = line[il];
#ifdef DBGPRINT
			printf("%c", line[il]);
#endif
		}
#ifdef DBGPRINT
		printf("\n");
		printf("[RIGHT@%d] ", cutPoint);
#endif
		for (int ir = cutPoint + 1; ir < len; ir++)
		{
			right.push_back(line[ir]);
			if (rp == 0 && (line[ir] == 'r' || line[ir] == 'b'))
				rp = line[ir];
#ifdef DBGPRINT
			printf("%c", line[ir]);
#endif
		}
#ifdef DBGPRINT
		printf("\n");
		printf("[@%d] lpivot=%c rpivot=%c\n", cutPoint, lp, rp);
#endif

		// count left
		int lc = 0;
		while (!left.empty())
		{
			char back = left.back();
			left.pop_back();
#ifdef DBGPRINT
			printf("[LEFT@%d] pop'd '%c' from L-back\n", cutPoint, back);
#endif
			if (back != lp && back != 'w')
				break;
			lc++;
		}

		// count right
		int rc = 0;
		while (!right.empty())
		{
			char front = right.front();
			right.pop_front();
#ifdef DBGPRINT
			printf("[RIGHT@%d] pop'd '%c' from R-front\n", cutPoint, front);
#endif
			if (front != rp && front != 'w')
				break;
			rc++;
		}

		int leng = lc + rc;
		if (leng > maxlen)
		{
			maxlen = leng;
			maxoff = cutPoint;
		}
	}
	fprintf(out, "%d %d %d", maxlen, maxoff + 1, maxoff + 2);

	fclose(out);
	return 0;
}
