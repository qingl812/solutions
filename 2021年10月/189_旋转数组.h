#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

// 额外数组
void rotate_1(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> newArr(n);
    for (int i = 0; i < n; ++i) {
        newArr[(i + k) % n] = nums[i];
    }
    nums.assign(newArr.begin(), newArr.end());
}

// 较难 未解决
void rotate_2(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    // 最大公约数
    int count = std::gcd(k, n);
    for (int start = 0; start < count; ++start) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % n;
            std::swap(nums[next], prev);
            current = next;
        } while (start != current);
    }
}

// 翻转实现
// 1 2 3 4 5 6 7
// 7 6 5 4 3 2 1
// 5 6 7 4 3 2 1
// 5 6 7 1 2 3 4
void rotate_3(vector<int>& nums, int k) {
    k %= nums.size();
    // 0 - n-1
    std::reverse(nums.begin(), nums.end());
    // 0 - k-1
    std::reverse(nums.begin(), nums.begin() + k);
    // k - n-1
    std::reverse(nums.begin() + k, nums.end());
}

void test(void (*rotate)(vector<int>&, int)) {
    vector<int> nums;
    nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    EXPECT_EQ(vector<int>({5, 6, 7, 1, 2, 3, 4}), nums);

    nums = {-1, -100, 3, 99};
    rotate(nums, 2);
    EXPECT_EQ(vector<int>({3, 99, -1, -100}), nums);

    nums = {-1};
    rotate(nums, 2);
    EXPECT_EQ(vector<int>({-1}), nums);

    nums = {1, 2};
    rotate(nums, 3);
    EXPECT_EQ(vector<int>({2, 1}), nums);
}

TEST(rotate, solution_1) { test(rotate_1); }
TEST(rotate, solution_2) { test(rotate_2); }
TEST(rotate, solution_3) { test(rotate_3); }