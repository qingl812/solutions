#include <vector>
using std::vector;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1, ans = n;
    while (left <= right) {
        int mid = ((right - left) / 2) + left;
        if (target <= nums[mid]) {
            ans = mid;
            right = mid - 1;
        } else
            left = mid + 1;
    }
    return ans;
}

TEST(searchInsert, normal) {
    EXPECT_EQ(2, searchInsert(vector<int>{1, 3, 5, 6}, 5));
    EXPECT_EQ(1, searchInsert(vector<int>{1, 3, 5, 6}, 2));
    EXPECT_EQ(4, searchInsert(vector<int>{1, 3, 5, 6}, 7));
    EXPECT_EQ(0, searchInsert(vector<int>{1, 3, 5, 6}, 0));
    EXPECT_EQ(0, searchInsert(vector<int>{1}, 0));
    EXPECT_EQ(1, searchInsert(vector<int>{1}, 2));
}