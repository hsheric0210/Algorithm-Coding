#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(),data.end(),[col](auto a,auto b){return a[col-1]==b[col-1]?a[0]>b[0]:a[col-1]<b[col-1];});
    int answer = 0;
    for (int i = row_begin; i <= row_end; i++)
    {
        int v = 0;
        for (int j = 0, k = data[i-1].size(); j < k; j++)
            v += data[i-1][j] % i;
        answer ^= v;
    }
    return answer;
}