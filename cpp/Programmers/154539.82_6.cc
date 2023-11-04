#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    // O(n^2)
    for (int i = 0, j = numbers.size(); i < j; i++)
    {
        for (int k = i + 1; k < j; k++)
            if (numbers[i] < numbers[k])
            {
                answer.push_back(numbers[k]);
                goto next_num;
            }
        answer.push_back(-1);
        next_num: ;
    }
    return answer;
}