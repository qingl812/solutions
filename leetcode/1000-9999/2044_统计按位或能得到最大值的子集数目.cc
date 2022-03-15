#include "common.h"

int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
    for (int i = 0; i < stateNumber; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (((i >> j) & 1) == 1) {
                cur |= nums[j];
            }
        }
        if (cur == maxValue) {
            cnt++;
        } else if (cur > maxValue) {
            maxValue = cur;
            cnt = 1;
        }
    }
    return cnt;
}

TEST(solution, countMaxOrSubsets) {
    vector<int> question;

    question = {3, 1};
    EXPECT_EQ(2, countMaxOrSubsets(question));

    question = {2, 2, 2};
    EXPECT_EQ(7, countMaxOrSubsets(question));

    question = {3, 2, 1, 5};
    EXPECT_EQ(6, countMaxOrSubsets(question));
}