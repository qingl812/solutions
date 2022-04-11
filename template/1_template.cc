#include "common.h"

void tmpl() {}
void tmpl2() {}

typedef void sol_fun();

class SolutionTest : public ::testing::TestWithParam<sol_fun*> {};

TEST_P(SolutionTest, floodFill) {
    vector<int> question;
    vector<int> expected;

    GetParam()();
    EXPECT_EQ(expected, question);
}

INSTANTIATE_TEST_SUITE_P(solution, SolutionTest,
                         ::testing::Values(tmpl, tmpl2));
