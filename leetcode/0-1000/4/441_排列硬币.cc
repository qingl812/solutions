#include "common.h"

inline size_t func(size_t x) {
    return x * (x + 1) / 2;
}

int arrangeCoins2(int n) {
    auto num = size_t(n);
    size_t left = 1, right = size_t(sqrt(2 * num) + 2);
    while (left < right) {
        auto mid = left + (right - left) / 2;
        if (func(mid) < num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return int(func(left) <= num ? left : left - 1);
}

int arrangeCoins(int n) {
    return (int)((sqrt((long long)8 * n + 1) - 1) / 2);
}

TEST(solution, arrangeCoins) {
    EXPECT_EQ(2, arrangeCoins(5));
    EXPECT_EQ(3, arrangeCoins(8));
    EXPECT_EQ(1, arrangeCoins(1));
    EXPECT_EQ(1, arrangeCoins(2));
    EXPECT_EQ(2, arrangeCoins(3));
    EXPECT_EQ(2, arrangeCoins(4));
    EXPECT_EQ(2, arrangeCoins(5));
    EXPECT_EQ(3, arrangeCoins(6));
    EXPECT_EQ(60070, arrangeCoins(1804289383));
    EXPECT_EQ(65535, arrangeCoins(2147483647));

    auto expected_func = [](int x) {
        if (x == 1)
            return 1;
        for (long long i = 1; i <= x; i++) {
            if (i * (i + 1) / 2 > static_cast<long long>(x))
                return static_cast<int>(i - 1);
        }
        return -1;
    };
    EXPECT_EQ(1, expected_func(1));
    EXPECT_EQ(60070, expected_func(1804289383));
    EXPECT_EQ(65535, expected_func(2147483647));
    tools::rand_int_check<int>(1000, 1, INT_MAX, arrangeCoins, expected_func);
}
