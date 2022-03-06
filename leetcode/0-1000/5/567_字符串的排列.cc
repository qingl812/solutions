#include "common.h"

bool checkInclusion(string s1, string s2) {
    size_t n1 = s1.size(), n2 = s2.size();
    size_t pos = 0;
    int diff = 0;
    vector<int> count(26);
    if (n1 > n2)
        return false;
    for (; pos < n1; pos++) {
        count[s1[pos] - 'a']--;
        count[s2[pos] - 'a']++;
    }
    for (auto i : count) {
        if (i != 0)
            diff++;
    }
    while (pos != n2 && diff != 0) {
        auto& x = count[s2[pos - n1] - 'a'];
        auto& y = count[s2[pos] - 'a'];
        diff += (x == 0) + (y == 0);
        x--;
        y++;
        diff -= (x == 0) + (y == 0);
        pos++;
    }
    return diff == 0;
}

TEST(solution, checkInclusion) {
    EXPECT_EQ(true, checkInclusion("ab", "eidbaooo"));
    EXPECT_EQ(false, checkInclusion("ab", "eidboaoo"));
    EXPECT_EQ(false, checkInclusion("hello", "ooolleoooleh"));
    EXPECT_EQ(false, checkInclusion("ccc", "cbac"));
}