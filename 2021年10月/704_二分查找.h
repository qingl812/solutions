#include <vector>
using std::vector;

int search(vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

TEST(searcha, normal) {
    EXPECT_EQ(4, search(vector<int>{-1, 0, 3, 5, 9, 12}, 9));
    EXPECT_EQ(-1, search(vector<int>{-1, 0, 3, 5, 9, 12}, 2));
    EXPECT_EQ(0, search(vector<int>{-1, 0, 3, 5, 9, 12}, -1));
    EXPECT_EQ(5, search(vector<int>{-1, 0, 3, 5, 9, 12}, 12));
    EXPECT_EQ(-1, search(vector<int>{-1, 0, 3, 5, 9, 12}, 13));
    EXPECT_EQ(-1, search(vector<int>{-1, 0, 3, 5, 9, 12}, -2));
    EXPECT_EQ(-1, search(vector<int>(), -2));
    EXPECT_EQ(-1, search(vector<int>{1}, -2));
    EXPECT_EQ(0, search(vector<int>{1}, 1));
}
