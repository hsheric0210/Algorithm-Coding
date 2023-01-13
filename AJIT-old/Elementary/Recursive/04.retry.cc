/* 기초 알고리즘(재귀호출) - 4. 부분집합 모두 출력하기 */

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <set>
#include <string>

std::set<std::string> possibility;

bool duplicated(std::string str)
{
	std::set<char> dups;
	for (auto a = str.begin(); a != str.end(); a++)
	{
		char ch = *a;
		if (dups.find(ch) != dups.end())
			return true;
		dups.insert(ch);
	}
	return false;
}

bool wrongorder(std::string str)
{
	int len = str.length();
	std::string sorted = str;
	std::sort(sorted.begin(), sorted.end(), std::less<char>());
	return str.compare(sorted) != 0;
}

void processRecursively(FILE *out, int n, std::string str)
{
	if (possibility.find(str) != possibility.end() || duplicated(str) || wrongorder(str))
		return;
	
	possibility.insert(str);
	if (!str.empty())
		fprintf(out, "%s\n", str.c_str());
	for (char a = 'a'; a < 'a' + n; a++)
		processRecursively(out, n, str + a);
}


int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = 0;
	fscanf(in, "%d", &n);
	fclose(in);

	processRecursively(out, n, "");
	fclose(out);
	return 0;
}
