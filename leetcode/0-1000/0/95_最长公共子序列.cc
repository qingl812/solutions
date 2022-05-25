#include "common.h"

int longestCommonSubsequence2(string text1, string text2) {
    int n1 = (int)text1.size();
    int n2 = (int)text2.size();
    vector<vector<int>> rect(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (text1[i - 1] != text2[j - 1])
                rect[i][j] = max(rect[i - 1][j], rect[i][j - 1]);
            else
                rect[i][j] = rect[i - 1][j - 1] + 1;
        }
    }
    return rect[n1][n2];
}

int longestCommonSubsequence(string text1, string text2) {
    if (text2.size() < text1.size())
        swap(text1, text2);
    auto a = new vector<int>(text1.size() + 1, 0);
    auto b = new vector<int>(text1.size() + 1, 0);

    for (auto c2 : text2) {
        auto it1 = a->begin() + 1;
        auto it2 = b->begin();
        for (auto c1 : text1) {
            if (c1 == c2)
                *(it2 + 1) = *(it1 - 1) + 1;
            else
                *(it2 + 1) = max(*it1, *it2);
            it1++;
            it2++;
        }
        swap(a, b);
    }
    return a->back();
}

TEST(solution, longestCommonSubsequence) {
    EXPECT_EQ(3, longestCommonSubsequence("abcde", "ace"));
    EXPECT_EQ(3, longestCommonSubsequence("abc", "abc"));
    EXPECT_EQ(0, longestCommonSubsequence("abc", "def"));
    EXPECT_EQ(1, longestCommonSubsequence("bsbininm", "jmjkbkjkv"));
}
