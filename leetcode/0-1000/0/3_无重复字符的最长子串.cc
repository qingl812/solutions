#include "common.h"

int lengthOfLongestSubstring(string s) {
    size_t n = s.size();
    size_t left = 0, right = 0;
    size_t max = 0;
    unordered_set<char> chars;
    while (right != n) {
        while (chars.find(s[right]) != chars.end()) {
            chars.erase(s[left++]);
        }
        chars.insert(s[right++]);
        max = std::max(max, right - left);
    }
    return static_cast<int>(max);
}

TEST(solution, lengthOfLongestSubstring) {
    EXPECT_EQ(3, lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, lengthOfLongestSubstring("bbbbb"));
    EXPECT_EQ(3, lengthOfLongestSubstring("pwwkew"));
}