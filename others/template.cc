#include "common.h"

void tmpl() {}

TEST(solution, tmpl) {
    vector<int> question;
    vector<int> expected;

    tmpl();
    EXPECT_EQ(expected, question);
}