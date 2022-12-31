/* 기초 알고리즘(그래프) - 6. 초콜릿 공장의 비밀 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <optional>

typedef struct _kiddo
{
	char id;
	int n;
} kid;

bool kidcmp_greater(kid a, kid b)
{
	return a.n > b.n;
}

bool kidcmp_lesser(kid a, kid b)
{
	return a.n < b.n;
}

int sol1(std::deque<int> dq)
{
	printf("Using solution #1\n");

	std::vector<kid> v;
	v.push_back({ 'A', 0 });
	v.push_back({ 'B', 0 });
	v.push_back({ 'C', 0 });

	while (!dq.empty())
	{
		auto min = std::min_element(dq.begin(), dq.end());
		auto vmin = std::min_element(v.begin(), v.end(), kidcmp_lesser);
		printf("Selected '%c' as its value '%d' is smallest.\n", vmin->id, vmin->n);
		vmin->n += *min;
		printf("Added %d to %c (now its value is %d)\n", *min, vmin->id, vmin->n);
		dq.erase(min);
	}

	for (int i = 0; i < 3; i++)
		printf("%c -> %d\n", v[i].id, v[i].n);

	int delta = std::max_element(v.begin(), v.end(), kidcmp_lesser)->n - std::min_element(v.begin(), v.end(), kidcmp_lesser)->n;
	printf("DELTA @ Solution_1 = %d\n", delta);
	return delta;
}

int sol2(std::deque<int> dq, int mean)
{
	printf("Using solution #2 (mean=%d)\n", mean);

	std::vector<kid> v;
	v.push_back({ 'A', 0 });
	v.push_back({ 'B', 0 });
	v.push_back({ 'C', 0 });

	int i = 0;
	while (!dq.empty())
	{
		while (!dq.empty() && i < 3)
		{
			auto min = std::min_element(dq.begin(), dq.end());
			int mval = *min;
			int index = i;
			int val = v[index].n;
			if (val + mval > mean && i < 3)
			{
				printf("Didn't added %d to %c as it will cause overflow (%d > %d)\n", mval, v[index].id, mval + val, mean);
				i++;
				continue;
			}

			printf("Added %d to %c\n", mval, v[index].id);
			v[index].n += mval;
			dq.erase(min);
		}

		if (dq.empty())
			break;

		// use all remainings
		auto min = std::min_element(dq.begin(), dq.end());
		auto vmin = std::min_element(v.begin(), v.end(), kidcmp_lesser);
		printf("Selected '%c' as its value '%d' is smallest.\n", vmin->id, vmin->n);
		vmin->n += *min;
		printf("Added %d to %c (now its value is %d)\n", *min, vmin->id, vmin->n);
		dq.erase(min);
	}


	for (int i = 0; i < 3; i++)
		printf("%c -> %d\n", v[i].id, v[i].n);

	int delta = std::max_element(v.begin(), v.end(), kidcmp_lesser)->n - std::min_element(v.begin(), v.end(), kidcmp_lesser)->n;
	printf("DELTA @ Solution_2 = %d\n", delta);
	return delta;
}

int sol3(std::deque<int> dq)
{
	printf("Using solution #3\n");

	std::vector<kid> v;
	v.push_back({ 'A', 0 });
	v.push_back({ 'B', 0 });
	v.push_back({ 'C', 0 });

	while (!dq.empty())
	{
		auto max = std::max_element(dq.begin(), dq.end());
		auto vmin = std::min_element(v.begin(), v.end(), kidcmp_lesser);
		printf("Selected '%c' as its value '%d' is smallest.\n", vmin->id, vmin->n);
		vmin->n += *max;
		printf("Added %d to %c (now its value is %d)\n", *max, vmin->id, vmin->n);
		dq.erase(max);
	}

	for (int i = 0; i < 3; i++)
		printf("%c -> %d\n", v[i].id, v[i].n);

	int delta = std::max_element(v.begin(), v.end(), kidcmp_lesser)->n - std::min_element(v.begin(), v.end(), kidcmp_lesser)->n;
	printf("DELTA @ Solution_3 = %d\n", delta);
	return delta;
}

int sol4(std::deque<int> dq, int mean)
{
	printf("Using solution #4 (mean=%d)\n", mean);

	std::vector<kid> v;
	v.push_back({ 'A', 0 });
	v.push_back({ 'B', 0 });
	v.push_back({ 'C', 0 });

	int i = 0;
	while (!dq.empty())
	{
		while (!dq.empty() && i < 3)
		{
			auto min = std::max_element(dq.begin(), dq.end());
			int mval = *min;
			int index = i;
			int val = v[index].n;
			if (val + mval > mean && i < 3)
			{
				printf("Didn't added %d to %c as it will cause overflow (%d > %d)\n", mval, v[index].id, mval + val, mean);
				i++;
				continue;
			}

			printf("Added %d to %c\n", mval, v[index].id);
			v[index].n += mval;
			dq.erase(min);
		}

		if (dq.empty())
			break;


		// use all remainings
		auto min = std::min_element(dq.begin(), dq.end());
		auto vmin = std::min_element(v.begin(), v.end(), kidcmp_lesser);
		printf("Selected '%c' as its value '%d' is smallest.\n", vmin->id, vmin->n);
		vmin->n += *min;
		printf("Added %d to %c (now its value is %d)\n", *min, vmin->id, vmin->n);
		dq.erase(min);
	}


	for (int i = 0; i < 3; i++)
		printf("%c -> %d\n", v[i].id, v[i].n);

	int delta = std::max_element(v.begin(), v.end(), kidcmp_lesser)->n - std::min_element(v.begin(), v.end(), kidcmp_lesser)->n;
	printf("DELTA @ Solution_4 = %d\n", delta);
	return delta;
}
 
int sol5(std::deque<int> dq)
{
	printf("Using solution #5\n");

	std::vector<kid> v;
	v.push_back({ 'A', 0 });
	v.push_back({ 'B', 0 });
	v.push_back({ 'C', 0 });

	std::sort(dq.begin(), dq.end(), std::greater<int>());
	v[0].n += dq.front();
	printf("Force push %d to '%c'.\n", v[0].n, v[0].id);
	dq.pop_front();
	v[1].n += dq.front();
	printf("Force push %d to '%c'.\n", v[1].n, v[1].id);
	dq.pop_front();

	while (!dq.empty())
	{
		auto max = std::min_element(dq.begin(), dq.end());
		auto vmin = std::min_element(v.begin(), v.end(), kidcmp_lesser);
		printf("Selected '%c' as its value '%d' is smallest.\n", vmin->id, vmin->n);
		vmin->n += *max;
		printf("Added %d to %c (now its value is %d)\n", *max, vmin->id, vmin->n);
		dq.erase(max);
	}

	for (int i = 0; i < 3; i++)
		printf("%c -> %d\n", v[i].id, v[i].n);

	int delta = std::max_element(v.begin(), v.end(), kidcmp_lesser)->n - std::min_element(v.begin(), v.end(), kidcmp_lesser)->n;
	printf("DELTA @ Solution_5 = %d\n", delta);
	return delta;
}

int sol6(std::deque<int> dq)
{
	printf("Using solution #6\n");

	std::vector<kid> v;
	v.push_back({ 'A', 0 });
	v.push_back({ 'B', 0 });
	v.push_back({ 'C', 0 });

	std::sort(dq.begin(), dq.end(), std::greater<int>());
	v[0].n += dq.front();
	printf("Force push %d to '%c'.\n", v[0].n, v[0].id);
	dq.pop_front();
	v[1].n += dq.front();
	printf("Force push %d to '%c'.\n", v[1].n, v[1].id);
	dq.pop_front();

	while (!dq.empty())
	{
		auto max = std::max_element(dq.begin(), dq.end());
		auto vmin = std::min_element(v.begin(), v.end(), kidcmp_lesser);
		printf("Selected '%c' as its value '%d' is smallest.\n", vmin->id, vmin->n);
		vmin->n += *max;
		printf("Added %d to %c (now its value is %d)\n", *max, vmin->id, vmin->n);
		dq.erase(max);
	}

	for (int i = 0; i < 3; i++)
		printf("%c -> %d\n", v[i].id, v[i].n);

	int delta = std::max_element(v.begin(), v.end(), kidcmp_lesser)->n - std::min_element(v.begin(), v.end(), kidcmp_lesser)->n;
	printf("DELTA @ Solution_6 = %d\n", delta);
	return delta;
}

int main(void)
{
	FILE* in = fopen("INPUT.TXT", "r");
	int n;
	fscanf(in, "%d", &n);
	std::deque<int> dq;
	for (int i = 0; i < n; i++)
	{
		int m = 0;
		fscanf(in, "%d", &m);
		dq.push_back(m);
	}
	fclose(in);

	int sum = 0;
	for (auto a = dq.begin(); a != dq.end(); a++)
		sum += *a;
	int mean = sum / 3;
	// std::sort(dq.begin(), dq.end()); // doesn't need to be sorted

	std::vector<int> deltas;
	deltas.push_back(sol1(dq));
	deltas.push_back(sol2(dq, mean));
	deltas.push_back(sol3(dq));
	deltas.push_back(sol4(dq, mean));
	deltas.push_back(sol5(dq));
	deltas.push_back(sol6(dq));

	FILE* out = fopen("OUTPUT.TXT", "w");
	fprintf(out, "%d", *std::min_element(deltas.begin(), deltas.end()));
	fclose(out);
	return 0;
}
