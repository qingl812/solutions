#include "common.h"

// https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode-solution-nipk/
// 解二不会推导
void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

TEST(solution, rotate) {
    vector<int> problem = {1, 2, 3, 4, 5, 6, 7};
    vector<int> answer = {5, 6, 7, 1, 2, 3, 4};
    rotate(problem, 3);
    EXPECT_EQ(answer, problem);

    problem = {-1, -100, 3, 99};
    answer = {3, 99, -1, -100};
    rotate(problem, 2);
    EXPECT_EQ(answer, problem);
}