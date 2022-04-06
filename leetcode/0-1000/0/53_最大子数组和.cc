#include "common.h"

// f(i) = max(f(i-1) + nums[i], nums[i])
int maxSubArray(vector<int>& nums) {
    int pre = 0,          // f(i-1)
        maxAns = nums[0]; // f(i)
    for (auto x : nums) {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}

// 方法 2
struct Status {
    int lSum, // [l,r] 内以 l 为左端点的最大子段和
        rSum, // [l,r] 内以 r 为右端点的最大子段和
        mSum, // [l,r] 内的最大子段和
        iSum; // [l,r] 的区间和
};

Status pushUp(Status l, Status r) {
    int iSum = l.iSum + r.iSum;
    int lSum = max(l.lSum, l.iSum + r.lSum);
    int rSum = max(r.rSum, r.iSum + l.rSum);
    int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
    return (Status){lSum, rSum, mSum, iSum};
};

Status get(vector<int>& a, int l, int r) {
    if (l == r) {
        return (Status){a[l], a[l], a[l], a[l]};
    }
    int m = (l + r) >> 1;
    Status lSub = get(a, l, m);
    Status rSub = get(a, m + 1, r);
    return pushUp(lSub, rSub);
}

int maxSubArray2(vector<int>& nums) {
    return get(nums, 0, nums.size() - 1).mSum;
}

TEST(solution, maxSubArray) {
    vector<int> question;

    question = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(6, maxSubArray(question));

    question = {1};
    EXPECT_EQ(1, maxSubArray(question));

    question = {5, 4, -1, 7, 8};
    EXPECT_EQ(23, maxSubArray(question));
}