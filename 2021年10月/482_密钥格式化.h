#include "../public.h"

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int cnt = 0;

        for (auto i = s.rbegin(); i != s.rend(); i++) {
            if (*i != '-') {
                ans.push_back(toupper(*i));
                cnt++;
                if (cnt % k == 0)
                    ans.push_back('-');
            }
        }
        if (ans.size() > 0 && ans.back() == '-')
            ans.pop_back();
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

void test_solution() {
    Solution sol;
    EXPECT_EQ_STRING("5F3Z-2E9W",
                     sol.licenseKeyFormatting("5F3Z-2e-9-w", 4).c_str());
    EXPECT_EQ_STRING("2-5G-3J",
                     sol.licenseKeyFormatting("2-5g-3-J", 2).c_str());
    EXPECT_EQ_STRING("A", sol.licenseKeyFormatting("a", 1).c_str());
    EXPECT_EQ_STRING("A-B", sol.licenseKeyFormatting("AB", 1).c_str());
    EXPECT_EQ_STRING("A-A-A-A",
                     sol.licenseKeyFormatting("a-a-a-a-", 1).c_str());
    EXPECT_EQ_STRING("", sol.licenseKeyFormatting("---", 3).c_str());
    EXPECT_EQ_STRING("A", sol.licenseKeyFormatting("--A-", 3).c_str());
}