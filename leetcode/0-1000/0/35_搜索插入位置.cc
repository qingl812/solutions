#include "common.h"

int searchInsert(vector<int> nums, int target) {
    int begin = 0, end = static_cast<int>(nums.size()) - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (nums[mid] >= target) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return begin;
}

TEST(solution, searchInsert) {
    EXPECT_EQ(2, searchInsert({1, 3, 5, 6}, 5));
    EXPECT_EQ(1, searchInsert({1, 3, 5, 6}, 2));
    EXPECT_EQ(4, searchInsert({1, 3, 5, 6}, 7));
    EXPECT_EQ(0, searchInsert({1, 3, 5, 6}, 0));
    EXPECT_EQ(3, searchInsert({1, 3, 5, 6}, 6));
    EXPECT_EQ(0, searchInsert({1}, 0));
    EXPECT_EQ(0, searchInsert({0}, 0));
    EXPECT_EQ(1, searchInsert({1}, 2));
}