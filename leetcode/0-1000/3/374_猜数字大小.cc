#include "common.h"

int pick;
int guess(int num) {
    if (num == pick)
        return 0;
    else if (num > pick)
        return -1;
    else
        return 1;
}

int guessNumber(int n) {
    int left = 1, right = n;
    while (left <= right) {
        int mid = (left / 2) + (right / 2) + (left & right & 1);
        switch (guess(mid)) {
        case 0:
            return mid;

        case 1:
            left = mid + 1;
            break;

        case -1:
            right = mid - 1;
            break;

        default:
            return -1;
        }
    }
    return -1;
}

TEST(solution, guessNumber) {
    pick = 6;
    EXPECT_EQ(pick, guessNumber(10));

    pick = 1;
    EXPECT_EQ(pick, guessNumber(1));

    pick = 1;
    EXPECT_EQ(pick, guessNumber(2));

    pick = 2;
    EXPECT_EQ(pick, guessNumber(2));
}