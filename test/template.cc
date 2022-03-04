#include "common.h"

void tmpl() {}

TEST(solution, tmpl) {
    vector<int> actual, expected;

    actual = {0};
    expected = {0};
    tmpl();
    EXPECT_EQ(expected, actual);
}