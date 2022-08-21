/* �߱�(߾) 4. ġŲ�԰�ʹ� */
/* ����: 10 */
/* ���� �ʿ�: O */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	int caseCount = 0, i, j;
	fscanf(in, "%d", &caseCount);

	for (i = 0; i < caseCount; i++)
	{
		// ������� 0-P, 1-M, 2-F, 3-C
		int data[8] = { 1 };
		for (j = 0; j < 4; j++)
			fscanf(in, "%d", data + j);


		printf("^Simulation started\n");

		// ��: �ֹ��� �� �ִ� ġŲ�� ����, ������: ���� ��
		div_t chickenOrderCount = div(data[1], data[0]);
		printf("Ordered chicken count: %d (Remaining money %d)\n", chickenOrderCount.quot, chickenOrderCount.rem);

		// ġŲ�� �ֹ��ϰ� ���� ������ ����
		int receivedCouponCount = chickenOrderCount.quot * data[3];
		printf("Received coupon count: %d\n", receivedCouponCount);

		// ��: ���� ���� �� ���� ġŲ�� �ֹ��ϴ� �� ����� ������ ����, ������: �׷��� ���� ������ ����
		//div_t couponUse = div(receivedCouponCount, data[2]);
		//printf("Received free chicken count: %d (Remaining coupon %d)\n", couponUse.quot, couponUse.rem);

		// ���� ���� ����
		// int remainCouponCount = couponUse.rem;

		// --- �� ������� ���̰� ����� �κ� ---
		// printf("--- DIFF POINT ---\n");

		// �������� ��Ų ġŲ�� �Բ� ���� �������� ��Ų ġŲ ����
		// int moreChickenCount = 0;

		// �������� �ֹ��� ġŲ�� �Բ� ���� ���� ���� �߰�
		// remainCouponCount += couponUse.quot * data[3];

		int couponDelta = data[2] - data[3];
		int couponUseCount = receivedCouponCount;
		do
		{
			couponUseCount -= couponDelta;
		} while (couponUseCount - couponDelta > 0);

		int delta = couponUseCount;

		printf("delta: %d\n", delta);

		//int loopCount = 0;
		//do
		//{
		//	// ��: ����� ġŲ�� �ֹ��ϰ� ���� ������ ���� (�ٽ�) �ֹ��� ġŲ�� ����, ������: �׷��� ���� ������ ����
		//	div_t couponReuse = div(remainCouponCount, data[2]);
		//	moreChickenCount += couponReuse.quot;
		//	remainCouponCount = couponReuse.rem;
		//	printf("[#%d] More free chicken count: %d (total %d, remaining coupon %d)\n", loopCount, couponReuse.quot, moreChickenCount, remainCouponCount);

		//	loopCount++;
		//} while (remainCouponCount >= data[2]);

		printf("$Simulation finished\n");

		// �� ����� ���� �� �ִ� ġŲ ������ ��
		// = '����� ġŲ�� �ֹ��ϰ� ���� ����'�� ���ؼ� �ֹ��� �� �ִ� ġŲ�� ����
		// (�� ����� �ܰ��̶� ������ ���� ����� ġŲ�� �ֹ��ϴ��� �ش� �ֹ��� ���� ������ ���� �� ������, ������ �� ����� �׷��� ���Ѵ�. ���̴� ���⼭ �߻��Ѵ�.)
		fprintf(out, "%d\n", delta);
	}

	fclose(in);
	fclose(out);
	return 0;
}
