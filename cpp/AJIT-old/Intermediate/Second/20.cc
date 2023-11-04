/* 중급(上) 20. 마야의달력 */
/* 점수: 90 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define HAAB_MONTHS 19
#define TZOLKIN_WORDS 20

// NOTE: Null-terminator length included
#define HAAB_MONTH_MAX_LEN 7

const char haabMonths[HAAB_MONTHS][HAAB_MONTH_MAX_LEN] = {
	"pop",
	"no",
	"zip",
	"zotz",
	"tzec",
	"xul",
	"yoxkin",
	"mol",
	"chen",
	"yax",
	"zac",
	"ceh",
	"mac",
	"kankin",
	"muan",
	"pax",
	"koyab",
	"cumhu",
	"uayet"
};

const char tzolkinWords[TZOLKIN_WORDS][9] = {
	"imix",
	"ik",
	"akbal",
	"kan",
	"chicchan",
	"cimi",
	"manik",
	"lamat",
	"muluk",
	"ok",
	"chuen",
	"eb",
	"ben",
	"ix",
	"mem",
	"cib",
	"caban",
	"eznab",
	"canac",
	"ahau"
};

typedef struct _DATE {
	short day, month, year;
} DATE;

int indexOfHaabMonth(char* monthStr)
{
	int i;
	for (i = 0; i < HAAB_MONTHS; i++)
	{
		if (!strcmp(monthStr, haabMonths[i]))
			return i;
	}
	return -1;
}

long long haabToAbsolute(DATE date)
{
	return date.year * 365 + 20 * (date.month) + date.day + 1;
}

DATE toTzolkin(long long absolute)
{
	lldiv_t yearDiv = lldiv(absolute, 260);
	absolute = yearDiv.rem;
	short month = (absolute % 20) - 1;
	if (month < 0)
		month += 20;
	short day = absolute % 13;
	if (day == 0)
		day = 13;
	printf("Tzolkin %d / %s(%d) / %d\n", yearDiv.quot, tzolkinWords[month], month, day);
	return { day, month, (short)yearDiv.quot };
}

void parseNPrint(FILE* in, FILE* out)
{
	int hyear, hday;
	char hmonth[HAAB_MONTH_MAX_LEN] = { 0 };
	fscanf(in, "%d %s %d", &hday, hmonth, &hyear);

	int hmonthidx = indexOfHaabMonth(hmonth);
	printf("haab month index: %d\n", hmonthidx);

	DATE hdate = { hday, hmonthidx, hyear };
	long long absolute = haabToAbsolute(hdate);

	printf("absolute: %d\n", absolute);

	DATE tdate = toTzolkin(absolute);

	fprintf(out, "%d %s %d\n", tdate.day, tzolkinWords[tdate.month], tdate.year);
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n, i;
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
		parseNPrint(in, out);

	fclose(in);
	fclose(out);
	return 0;
}
