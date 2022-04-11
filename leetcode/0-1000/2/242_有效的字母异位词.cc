#include "common.h"

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    int n = s.size();
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0)
            return false;
    }
    return true;
}

TEST(solution, isAnagram) {
    EXPECT_EQ(true, isAnagram("anagram", "nagaram"));
    EXPECT_EQ(false, isAnagram("rat", "car"));
}