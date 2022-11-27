#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

int main(int argc, char** argv) {

	int caseIndex, orderedChickenTotalByCoupon, orderedChickenByOrder, totalCouponCount, caseCount, chickenPrice, totalMoney, requiredCouponCountToOrder, recvCouponPerOrder;
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "w");

	fscanf(in, "%d", &caseCount);

	for (caseIndex = 0; caseIndex < caseCount; caseIndex++) {
		fscanf(in, "%d %d %d %d", &chickenPrice, &totalMoney, &requiredCouponCountToOrder, &recvCouponPerOrder);

		totalCouponCount = totalMoney / chickenPrice * recvCouponPerOrder; //ġŲ��� ���� �� ������

		orderedChickenByOrder = totalCouponCount / requiredCouponCountToOrder; //�ܰ� �ƴ� �л��� �������� �� ���� ������

		for (orderedChickenTotalByCoupon = 0; totalCouponCount >= requiredCouponCountToOrder; orderedChickenTotalByCoupon++)
		{
			// ������ F���� �������� ���� ġŲ�� �ֹ��ص� �ٽ� ������ C�� �ִϱ� ó������ �� ���� �������� F-C �� ��ŭ�� ���� ���� ����.
			totalCouponCount -= (requiredCouponCountToOrder - recvCouponPerOrder);
			// totalCouponCount -= requiredCouponCountToOrder; totalCouponCount += recvCouponPerOrder;
		}

		fprintf(out, "%d\n", orderedChickenTotalByCoupon - orderedChickenByOrder);

	}

	fclose(in);
	fclose(out);

	return 0;

}