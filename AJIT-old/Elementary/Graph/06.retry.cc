/* 기초 알고리즘(그래프) - 6. 초콜릿 공장의 비밀 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <optional>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int i, avg, m, n, s, sol1_delta, sol2_delta;
	vector<int> v;

	in >> n;
	for (i = 0, s = 0; i < n; i++) {
		in >> m;
		v.push_back(m);
		s += m;
	}
	avg = s / 3;
	sort(v.begin(), v.end(), greater<int>());

	int sol1[3] = { 0 };
	// increase in order
	for (i = 0; i < v.size(); i++) {
		if (sol1[0] + v[i] <= avg) sol1[0] += v[i];
		else if (sol1[1] + v[i] <= avg) sol1[1] += v[i];
		else if (sol1[2] + v[i] <= avg) sol1[2] += v[i];
		else break;
	}

	// consume all remainings
	for (; i < v.size(); i++) {
		if (sol1[0] <= sol1[1] && sol1[0] <= sol1[2]) sol1[0] += v[i];
		else if (sol1[1] <= sol1[0] && sol1[1] <= sol1[2]) sol1[1] += v[i];
		else sol1[2] += v[i];
	}
	
	// calc delta
	sort(sol1, sol1 + 3);
	sol1_delta = sol1[2] - sol1[0];

	int sol2[3] = { 0 };
	sol2[0] += v[0];
	sol2[1] += v[1];
	for (i = 2; i < v.size(); i++) {
		sort(sol2, sol2 + 3);
		sol2[0] += v[i];
	}

	// calc delta
	sort(sol2, sol2 + 3);
	sol2_delta = sol2[2] - sol2[0];
	out << (sol1_delta < sol2_delta ? sol1_delta : sol2_delta);
	return 0;
}