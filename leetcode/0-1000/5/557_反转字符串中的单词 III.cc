#include "common.h"

string reverseWords(string s) {
    string ret;
    auto length = s.length();
    int i = 0;
    while (i < length) {
        int start = i;
        while (i < length && s[i] != ' ') {
            i++;
        }
        for (int p = i - 1; p >= start; p--) {
            ret.push_back(s[p]);
        }
        if (s[i] == ' ') {
            i++;
            ret.push_back(' ');
        }
    }
    return ret;
}

TEST(solution, reverseWords) {
    EXPECT_EQ("s'teL ekat edoCteeL tsetnoc",
              reverseWords("Let's take LeetCode contest"));
    EXPECT_EQ("God Ding", reverseWords("doG gniD"));
}