/* 중급(下) 레벨테스트 4. 최고의해커창민이3 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 500

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int shift = 0;
	char* buffer = (char*)calloc(MAX_LENGTH, sizeof(char));
	fscanf(in, "%d", &shift);
	fgetc(in); // consume newline char
	fgets(buffer, MAX_LENGTH, in);

	for (int i = 0; i < strlen(buffer); i++)
	{
		int charindex = buffer[i];
		charindex -= shift;
		if (charindex < 'A')
			charindex += 26;
		buffer[i] = charindex;
	}

	fputs(buffer, out);

	fclose(in);
	fclose(out);
	return 0;
}
