#include "common.h"

// 如果所有数都小于 target return nums.size();
// 如果所有数都大于 target return 0;
// lower = false 返回第一个大于 target 的下标
// lower = true 返回第一个大于等于 target 的下标
int binarySearch(vector<int>& nums, int target, bool lower = false) {
    int left = 0, right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (lower && nums[mid] == target))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0)
        return {-1, -1};

    int left = binarySearch(nums, target, true);
    int right = binarySearch(nums, target, false);
    if (left != nums.size() && nums[left] == target &&
        nums[right - 1] == target) {
        return vector<int>{left, right - 1};
    }

    return {-1, -1};
}

TEST(solution, searchRange) {
    vector<int> question;
    vector<int> expected;

    question = {5, 7, 7, 8, 8, 10};
    // binarySearch test
    EXPECT_EQ(6, binarySearch(question, 11));
    EXPECT_EQ(0, binarySearch(question, 0));
    EXPECT_EQ(1, binarySearch(question, 5));
    EXPECT_EQ(3, binarySearch(question, 7));
    EXPECT_EQ(5, binarySearch(question, 8));
    EXPECT_EQ(6, binarySearch(question, 10));

    EXPECT_EQ(6, binarySearch(question, 11, true));
    EXPECT_EQ(0, binarySearch(question, 0, true));
    EXPECT_EQ(0, binarySearch(question, 5, true));
    EXPECT_EQ(1, binarySearch(question, 7, true));
    EXPECT_EQ(3, binarySearch(question, 8, true));
    EXPECT_EQ(5, binarySearch(question, 10, true));

    // solution
    question = {5, 7, 7, 8, 8, 10};
    expected = {3, 4};
    EXPECT_EQ(expected, searchRange(question, 8));

    question = {5, 7, 7, 8, 8, 10};
    expected = {-1, -1};
    EXPECT_EQ(expected, searchRange(question, 6));

    question = {};
    expected = {-1, -1};
    EXPECT_EQ(expected, searchRange(question, 0));

    question = {2, 2};
    expected = {-1, -1};
    EXPECT_EQ(expected, searchRange(question, 3));

    question = {2, 2};
    expected = {-1, -1};
    EXPECT_EQ(expected, searchRange(question, 0));

    question = {2};
    expected = {0, 0};
    EXPECT_EQ(expected, searchRange(question, 2));

    question = {2};
    expected = {-1, -1};
    EXPECT_EQ(expected, searchRange(question, 3));
}