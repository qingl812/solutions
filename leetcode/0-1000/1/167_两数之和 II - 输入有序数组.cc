#include "common.h"

vector<int> twoSum(vector<int>& numbers, int target) {
    auto left = numbers.begin(), right = numbers.end() - 1;
    while(true) {
        int sum = *left + *right;
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            return {int(left - numbers.begin()) + 1,
                    int(right - numbers.begin()) + 1};
        }
    }
}

TEST(solution, twoSum) {
    vector<int> problem, answer;

    problem = {2, 7, 11, 15};
    answer = {1, 2};
    problem = twoSum(problem, 9);
    EXPECT_EQ(answer, problem);

    problem = {2, 3, 4};
    answer = {1, 3};
    problem = twoSum(problem, 6);
    EXPECT_EQ(answer, problem);

    problem = {-1, 0};
    answer = {1, 2};
    problem = twoSum(problem, -1);
    EXPECT_EQ(answer, problem);
}