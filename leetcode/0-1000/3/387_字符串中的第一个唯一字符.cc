#include "common.h"

int firstUniqChar(const string& s) {
    unordered_map<char, bool> hash_map;

    for (int i = s.size() - 1; i >= 0; i--) {
        auto pos = hash_map.find(s[i]);
        if (pos == hash_map.end()) {
            hash_map.emplace(s[i], true);
        } else if (pos->second) {
            pos->second = false;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (hash_map[s[i]])
            return i;
    }
    return -1;
}

TEST(solution, firstUniqChar) {
    EXPECT_EQ(0, firstUniqChar("leetcode"));
    EXPECT_EQ(2, firstUniqChar("loveleetcode"));
    EXPECT_EQ(-1, firstUniqChar("aabb"));
    EXPECT_EQ(8, firstUniqChar("dddccdbba"));
}