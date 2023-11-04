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

		totalCouponCount = totalMoney / chickenPrice * recvCouponPerOrder; //치킨사고 받은 총 쿠폰수

		orderedChickenByOrder = totalCouponCount / requiredCouponCountToOrder; //단골 아닌 학생의 쿠폰으로 산 닭의 마리수

		for (orderedChickenTotalByCoupon = 0; totalCouponCount >= requiredCouponCountToOrder; orderedChickenTotalByCoupon++)
		{
			// 어차피 F개의 쿠폰으로 무료 치킨을 주문해도 다시 쿠폰을 C개 주니까 처음부터 총 쿠폰 갯수에서 F-C 개 만큼만 빼도 식은 성립.
			totalCouponCount -= (requiredCouponCountToOrder - recvCouponPerOrder);
			// totalCouponCount -= requiredCouponCountToOrder; totalCouponCount += recvCouponPerOrder;
		}

		fprintf(out, "%d\n", orderedChickenTotalByCoupon - orderedChickenByOrder);

	}

	fclose(in);
	fclose(out);

	return 0;

}