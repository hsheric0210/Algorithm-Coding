/* Áß±Þ(ß¾) 6. Å«¼öÀÇ°ö¼À2 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	long long m = 0, n = 0, i;
	fscanf(in, "%d %d", &m, &n);

	int prevNumber = n;
	long long result = 1;

	for (i = m; i <= n; i++)
		result *= i;

	fprintf(out, "%d", result);

	fclose(in);
	fclose(out);
	return 0;
}
