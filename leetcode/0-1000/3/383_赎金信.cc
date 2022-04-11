#include "common.h"

bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size())
        return false;

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    for (auto i : magazine)
        cnt[i - 'a']++;
    for (auto i : ransomNote) {
        cnt[i - 'a']--;
        if (cnt[i - 'a'] < 0)
            return false;
    }
    return true;
}

TEST(solution, canConstruct) {
    EXPECT_EQ(false, canConstruct("a", "b"));
    EXPECT_EQ(false, canConstruct("aa", "bb"));
    EXPECT_EQ(true, canConstruct("aa", "aab"));
}