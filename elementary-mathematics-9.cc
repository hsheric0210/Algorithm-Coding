/* 기초 알고리즘(수학) - 9. 스위치상태 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");

	int switchCount = 0;
	fscanf(in, "%d", &switchCount);

	int* switchStates = (int*)calloc(switchCount, sizeof(int));
	for (int i = 0; i < switchCount; i++)
		fscanf(in, " %d", switchStates + i);

	int studentCount = 0;
	fscanf(in, "%d", &studentCount);

	int* studentGender = (int*)calloc(studentCount, sizeof(int));
	int* studentSwitch = (int*)calloc(studentCount, sizeof(int));

	for (int i = 0; i < studentCount; i++)
		fscanf(in, " %d %d", studentGender + i, studentSwitch + i);

	FILE* out = fopen("OUTPUT.TXT", "w");

	printf("switchCnt=%d\n", switchCount);

	for (int i = 0; i < studentCount; i++)
	{
		int gender = studentGender[i];
		int specifiedSwitch = studentSwitch[i];

		if (gender == 1)
		{
			// male
			for (int j = specifiedSwitch - 1; j < switchCount /*prevent overflow*/; j += specifiedSwitch)
			{
				printf("[MALE@%d] Toggled switch @ %d\n", i, j);
				switchStates[j] = !switchStates[j];
			}
		}
		else
		{
			// female
			for (int off = 0; specifiedSwitch + off <= switchCount && specifiedSwitch - off >= 1 /*prevent overflow*/; off++)
			{
				// if not symmetry
				if (switchStates[specifiedSwitch + off - 1] != switchStates[specifiedSwitch - off - 1])
					break; // exit

				printf("[FEMALE@%d] Toggled switch @ %d and %d (off=%d)\n", i, specifiedSwitch + off - 1, specifiedSwitch - off - 1, off);
				switchStates[specifiedSwitch + off - 1] = !switchStates[specifiedSwitch + off - 1];
				if (off > 0) // prevent re-toggling
					switchStates[specifiedSwitch - off - 1] = !switchStates[specifiedSwitch - off - 1];

			}
		}
	}

	free(studentGender);
	free(studentSwitch);

	for (int i = 0; i < switchCount; i++)
	{
		if (i > 0 && i % 20 == 0)
			fprintf(out, "\n");
		fprintf(out, "%d ", switchStates[i]);
	}

	free(switchStates);

	fclose(in);
	fclose(out);
	return 0;
}
