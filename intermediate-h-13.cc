/* �߱�(߾) 13. toilet */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int n = -1, i;
	fscanf(in, "%d", &n);

	int minCount;
	if (n % 3 == 0)
		minCount = n / 3;
	else
		// ����: (��� C������) �Ǽ��� -> ������ ��ȯ �� '�Ҽ��� �Ʒ��� �������.' ��, "����(floor)"�ȴ�.

		// �̴� ���������� ������������ ���������̴�. �⺻������ ���������� ���������� ���� �Ǽ��� ���� ���, "����(floor)"�Ǿ� '��� ������'������ �� �Ϳ��� '��'���� ���� �Ͱ� ���� ����� ���´�.
		// ��, 'a / b' = 'div(a, b).quot'
		minCount = n / 3 + 1;
	int maxCount;
	if (n % 2 == 0)
		maxCount = n / 2;
	else
		maxCount = n / 2 + 1;
	fprintf(out, "%d %d", maxCount, minCount);

	fclose(in);
	fclose(out);
	return 0;
}
