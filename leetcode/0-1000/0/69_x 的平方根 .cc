#include "common.h"

int mySqrt(int x) {
    if (x == 1)
        return 1;
    long long left = 0, right = x / 2;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (mid * mid > x) {
            right = mid - 1;
        } else
            left = mid + 1;
    }
    return static_cast<int>(left * left <= x ? left : left - 1);
}

TEST(solution, mySqrt) {
    EXPECT_EQ(1, mySqrt(1));
    EXPECT_EQ(2, mySqrt(4));
    EXPECT_EQ(2, mySqrt(8));
    EXPECT_EQ(46340, mySqrt(2147395600));

    auto expected_fun = [](int n) { return int(sqrt(n)); };
    tools::rand_int_check<int>(10000, 0, INT_MAX, mySqrt, expected_fun);
}