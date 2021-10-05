// The API isBadVersion is defined for you.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 1, high = n;
    while (low < high) {
        int mid = (high - low) / 2 + low;

        if (isBadVersion(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int badVersion;
bool isBadVersion(int version) { return version >= badVersion; }

int test_firstBadVersion(int n, int badVer) {
    badVersion = badVer;
    return firstBadVersion(n);
}

TEST(firstBadVersion, isBadVersion) {
    badVersion = 10;
    EXPECT_TRUE(isBadVersion(10));
    EXPECT_TRUE(isBadVersion(11));
    EXPECT_FALSE(isBadVersion(1));
    EXPECT_FALSE(isBadVersion(2));
}

TEST(firstBadVersion, normal) {
    EXPECT_EQ(4, test_firstBadVersion(5, 4));
    EXPECT_EQ(1, test_firstBadVersion(1, 1));
    EXPECT_EQ(1, test_firstBadVersion(10, 1));
    EXPECT_EQ(10, test_firstBadVersion(10, 10));
}