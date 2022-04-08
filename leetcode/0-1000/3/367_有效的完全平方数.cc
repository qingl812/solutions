#include "common.h"

bool isPerfectSquare(int num) {
    // int 取值范围内最大的平方数
    if (num > 2147395600)
        return false;

    int i = 1;
    while (true) {
        int t = i * i - num;
        if (t > 0)
            return false;
        else if (t == 0)
            return true;
        i++;
    }
}

TEST(solution, isPerfectSquare) {
    EXPECT_EQ(true, isPerfectSquare(1));
    EXPECT_EQ(true, isPerfectSquare(16));
    EXPECT_EQ(false, isPerfectSquare(14));
    EXPECT_EQ(false, isPerfectSquare(2147483647));
}