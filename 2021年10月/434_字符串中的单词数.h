#include <string>
using std::string;

int countSegments(string s) {
    bool sign = false;
    int ans = 0;
    for (auto i : s) {
        if (i == ' ') {
            if (sign) {
                ans += 1;
                sign = false;
            }
        } else
            sign = true;
    }
    if (sign)
        ans += 1;
    return ans;
}

TEST(countSegments, normal) {
    EXPECT_EQ(5, countSegments("Hello, my name is John"));
    EXPECT_EQ(5, countSegments("  Hello, my name is John"));
    EXPECT_EQ(5, countSegments("  Hello,  my name is John"));
    EXPECT_EQ(1, countSegments("h"));
    EXPECT_EQ(0, countSegments(" "));
    EXPECT_EQ(1, countSegments(" h "));
    EXPECT_EQ(3, countSegments("a h b"));
    EXPECT_EQ(0, countSegments("      "));
}