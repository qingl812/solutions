#include "common.h"

int search(vector<int> nums, int target) {
    int begin = 0, end = static_cast<int>(nums.size() - 1);
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (nums[mid] > target) {
            end = mid - 1;
        } else if (nums[mid] < target) {
            begin = mid + 1;
        } else
            return mid;
    }
    return -1;
}

TEST(solution, search) {
    EXPECT_EQ(4, search({-1, 0, 3, 5, 9, 12}, 9));
    EXPECT_EQ(-1, search({-1, 0, 3, 5, 9, 12}, 2));
    EXPECT_EQ(0, search({-1, 0, 3, 5, 9, 12}, -1));
    EXPECT_EQ(5, search({-1, 0, 3, 5, 9, 12}, 12));
    EXPECT_EQ(4, search({-1, 0, 3, 5, 9}, 9));
    EXPECT_EQ(0, search({0}, 0));
    EXPECT_EQ(-1, search({2, 5}, 0));
}