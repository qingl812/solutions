#include <string>
using std::string;

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

TEST(licenseKeyFormatting, normal) {
    EXPECT_STREQ("5F3Z-2E9W", licenseKeyFormatting("5F3Z-2e-9-w", 4).c_str());
    EXPECT_STREQ("2-5G-3J", licenseKeyFormatting("2-5g-3-J", 2).c_str());
    EXPECT_STREQ("A", licenseKeyFormatting("a", 1).c_str());
    EXPECT_STREQ("A-B", licenseKeyFormatting("AB", 1).c_str());
    EXPECT_STREQ("A-A-A-A", licenseKeyFormatting("a-a-a-a-", 1).c_str());
    EXPECT_STREQ("", licenseKeyFormatting("---", 3).c_str());
    EXPECT_STREQ("A", licenseKeyFormatting("--A-", 3).c_str());
}