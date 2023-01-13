/* 중급(上) 4. 치킨먹고싶다 */
/* 점수: 10 */
/* 도움 필요: O */

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
		// 순서대로 0-P, 1-M, 2-F, 3-C
		int data[8] = { 1 };
		for (j = 0; j < 4; j++)
			fscanf(in, "%d", data + j);


		printf("^Simulation started\n");

		// 몫: 주문할 수 있는 치킨의 갯수, 나머지: 남은 돈
		div_t chickenOrderCount = div(data[1], data[0]);
		printf("Ordered chicken count: %d (Remaining money %d)\n", chickenOrderCount.quot, chickenOrderCount.rem);

		// 치킨을 주문하고 받은 쿠폰의 갯수
		int receivedCouponCount = chickenOrderCount.quot * data[3];
		printf("Received coupon count: %d\n", receivedCouponCount);

		// 몫: 받은 쿠폰 중 무료 치킨을 주문하는 데 사용한 쿠폰의 갯수, 나머지: 그러고 남은 쿠폰의 갯수
		//div_t couponUse = div(receivedCouponCount, data[2]);
		//printf("Received free chicken count: %d (Remaining coupon %d)\n", couponUse.quot, couponUse.rem);

		// 남은 쿠폰 갯수
		// int remainCouponCount = couponUse.rem;

		// --- 두 사람간의 차이가 생기는 부분 ---
		// printf("--- DIFF POINT ---\n");

		// 쿠폰으로 시킨 치킨과 함께 받은 쿠폰으로 시킨 치킨 갯수
		// int moreChickenCount = 0;

		// 쿠폰으로 주문한 치킨과 함께 받은 쿠폰 갯수 추가
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
		//	// 몫: 무료로 치킨을 주문하고 받은 쿠폰을 통해 (다시) 주문한 치킨의 갯수, 나머지: 그러고 남은 쿠폰의 갯수
		//	div_t couponReuse = div(remainCouponCount, data[2]);
		//	moreChickenCount += couponReuse.quot;
		//	remainCouponCount = couponReuse.rem;
		//	printf("[#%d] More free chicken count: %d (total %d, remaining coupon %d)\n", loopCount, couponReuse.quot, moreChickenCount, remainCouponCount);

		//	loopCount++;
		//} while (remainCouponCount >= data[2]);

		printf("$Simulation finished\n");

		// 두 사람이 먹을 수 있는 치킨 갯수의 차
		// = '무료로 치킨을 주문하고 받은 쿠폰'을 통해서 주문할 수 있는 치킨의 갯수
		// (한 사람은 단골이라 쿠폰을 통해 무료로 치킨을 주문하더라도 해당 주문을 통해 쿠폰을 받을 수 있지만, 나머지 한 사람은 그러지 못한다. 차이는 여기서 발생한다.)
		fprintf(out, "%d\n", delta);
	}

	fclose(in);
	fclose(out);
	return 0;
}
