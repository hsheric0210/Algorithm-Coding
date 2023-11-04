/* 기초 알고리즘(그래프) - 5. 숨겨진 단어 찾기 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <optional>

int m, n;
char* block;

typedef struct _coord {
	int x;
	int y;

	int pack()
	{
		return y * n + x;
	}

	struct _coord offset(int offx, int offy)
	{
		return { x + offx, y + offy };
	}

	static struct _coord unpack(int packed)
	{
		return { packed % m, packed / m };
	}

	bool valid()
	{
		return x >= 0 && x < n && y >= 0 && y < m;
	}
} coord;

bool findInternal(int chlen, char* ch, int index, coord startPos, int offx, int offy, coord *endPos)
{

	if (index >= chlen)
	{
		return false;
	}

	coord off = startPos;
	if (!off.valid())
	{
		return false;
	}

	if (block[off.pack()] != ch[index])
	{
		return false;
	}

	// it is the last element?
	if (index == chlen - 1)
	{
		*endPos = off;
		return true;
	}

	return findInternal(chlen, ch, index + 1, startPos.offset(offx, offy), offx, offy, endPos);
}

std::optional<std::tuple<coord, coord>> find(int len, char* text)
{
	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++)
		{
			coord entryPos = { x, y };
			coord endPos = { -1, -1 };
			bool found = false;
			found = found || findInternal(len, text, 0, entryPos, 1, 0, &endPos);
			found = found || findInternal(len, text, 0, entryPos, 0, 1, &endPos);
			found = found || findInternal(len, text, 0, entryPos, 1, 1, &endPos);
			found = found || findInternal(len, text, 0, entryPos, -1, 1, &endPos);
			if (found && endPos.valid())
				return std::make_tuple(entryPos, endPos);
		}
	return std::nullopt;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	fscanf(in, "%d %d", &m, &n);

	printf("m = %d, n = %d\n", m, n);
	block = (char*)calloc(m * n + 1, sizeof(char));
	if (block == nullptr)
	{
		printf("block alloc fail\n");
		return 1;
	}

	for (int i = 0; i < m; i++)
	{
		char* line = (char*)calloc(n + 1, sizeof(char));
		if (line == nullptr)
		{
			printf("line alloc fail @ i = %d\n", i);
			return 1;
		}

		fscanf(in, "%s", line);
		strcat(block, line);
		free(line);
	}

	FILE* out = fopen("OUTPUT.TXT", "w");
	for (int i = 0; i < 3; i++)
	{
		char *needle = (char*)calloc(10, sizeof(char));
		if (needle == nullptr)
		{
			printf("needle @ %d alloc fail\n", i);
			return 1;
		}

		fscanf(in, "%s", needle);
		auto a = find(strlen(needle), needle);
		if (a.has_value())
		{
			auto &value = a.value();
			auto &start = std::get<0>(value);
			auto &end = std::get<1>(value);
			fprintf(out, "%d %d %d %d\n", start.y + 1, start.x + 1, end.y + 1, end.x + 1);
		}
		else
			printf("'%s' not found.\n", needle);
	}

	fclose(in);
	fclose(out);
	return 0;
}
