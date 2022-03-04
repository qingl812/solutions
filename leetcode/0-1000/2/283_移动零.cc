#include "common.h"

void moveZeroes(vector<int>& nums) {
    int pos = 0, n = nums.size();
    for (auto& i : nums) {
        if (i) {
            nums[pos++] = i;
        }
    }
    while (pos < n) {
        nums[pos++] = 0;
    }
}

TEST(solution, moveZeroes) {
    vector<int> problem, answer;

    problem = {0, 1, 0, 3, 12};
    answer = {1, 3, 12, 0, 0};
    moveZeroes(problem);
    EXPECT_EQ(answer, problem);

    problem = {0};
    answer = {0};
    moveZeroes(problem);
    EXPECT_EQ(answer, problem);
}