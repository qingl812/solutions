#include <algorithm>
#include <vector>
using std::vector;

vector<int> sortedSquares(vector<int>& nums) {
    int pos = nums.size();
    vector<int> ans(pos);

    pos--;
    for (auto left = nums.begin(), right = nums.end() - 1; pos >= 0; pos--) {
        // 等于号必须写在前面，不然当 right==nums.begin()时，right--不合法
        if (abs(*left) >= abs(*right)) {
            ans[pos] = *left * *left;
            left++;
        } else {
            ans[pos] = *right * *right;
            right--;
        }
    }

    return ans;
}

TEST(sortedSquares, normal) {
    EXPECT_EQ(vector<int>({4, 9, 9, 49, 121}),
              sortedSquares(vector<int>({-7, -3, 2, 3, 11})));
    EXPECT_EQ(vector<int>({0, 1, 9, 16, 100}),
              sortedSquares(vector<int>({-4, -1, 0, 3, 10})));
    EXPECT_EQ(vector<int>({4}), sortedSquares(vector<int>({-2})));
    EXPECT_EQ(vector<int>({0}), sortedSquares(vector<int>({0})));
}