#include "common.h"

int badVersion = 0;

bool isBadVersion(int version) {
    return version >= badVersion;
}

int firstBadVersion(int n) {
    int begin = 1, end = n;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (isBadVersion(mid)) {
            end = mid - 1;
            if (!isBadVersion(end))
                return end + 1;
        } else {
            begin = mid + 1;
            if (isBadVersion(begin))
                return begin;
        }
    }
    return -1;
}

TEST(solution, firstBadVersion) {
    badVersion = 4;
    EXPECT_EQ(badVersion, firstBadVersion(5));

    badVersion = 1;
    EXPECT_EQ(badVersion, firstBadVersion(11));

    badVersion = 10;
    EXPECT_EQ(badVersion, firstBadVersion(13));

    badVersion = 24;
    EXPECT_EQ(badVersion, firstBadVersion(24));

    badVersion = 1;
    EXPECT_EQ(badVersion, firstBadVersion(1));

    badVersion = 1702766719;
    EXPECT_EQ(badVersion, firstBadVersion(2126753390));
}
