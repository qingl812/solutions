#include "common.h"

vector<int> sortedSquares(vector<int> nums) {
    for (auto& i : nums)
        i = i * i;
    int n = nums.size();
    vector<int> result;
    if (n == 1) {
        result.push_back(nums[0]);
        return result;
    }
    stack<int> under; // 0以下数字的平方
    int pos = 0;
    while (pos != n - 1 && nums[pos] >= nums[pos + 1]) {
        under.push(nums[pos++]);
    }
    while (!under.empty() && pos != n) {
        if (nums[pos] < under.top()) {
            result.push_back(nums[pos++]);
        } else {
            result.push_back(under.top());
            under.pop();
        }
    }
    while (!under.empty()) {
        result.push_back(under.top());
        under.pop();
    }
    while (pos != n) {
        result.push_back(nums[pos++]);
    }
    return result;
}

TEST(solution, sortedSquares) {
    EXPECT_EQ(vector<int>({0, 1, 9, 16, 100}),
              sortedSquares({-4, -1, 0, 3, 10}));
    EXPECT_EQ(vector<int>({4, 9, 9, 49, 121}),
              sortedSquares({-7, -3, 2, 3, 11}));
    EXPECT_EQ(vector<int>({16}), sortedSquares({4}));
    EXPECT_EQ(vector<int>({1, 4, 9, 16}), sortedSquares({-4, -3, -2, -1}));
    EXPECT_EQ(vector<int>({1, 4, 9, 25}), sortedSquares({-5, -3, -2, -1}));
}