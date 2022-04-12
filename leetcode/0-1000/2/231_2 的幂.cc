#include "common.h"

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

TEST(solution, isPowerOfTwo) {
    EXPECT_EQ(true, isPowerOfTwo(1));
    EXPECT_EQ(true, isPowerOfTwo(2 * 2));
    EXPECT_EQ(true, isPowerOfTwo(2 * 2));
    EXPECT_EQ(true, isPowerOfTwo(2 * 2 * 2));

    EXPECT_EQ(false, isPowerOfTwo(5));
    EXPECT_EQ(false, isPowerOfTwo(2 * 2 * 2 - 1));
    EXPECT_EQ(false, isPowerOfTwo(static_cast<int>(std::pow(2, 8)) - 3));
}