#include "common.h"

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int x : nums) {
        if (s.find(x) != s.end()) {
            return true;
        }
        s.insert(x);
    }
    return false;
}

TEST(solution, containsDuplicate) {
    vector<int> question;

    question = {1, 2, 3, 1};
    EXPECT_EQ(true, containsDuplicate(question));

    question = {1, 2, 3, 4};
    EXPECT_EQ(false, containsDuplicate(question));

    question = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    EXPECT_EQ(true, containsDuplicate(question));

    question = {1, 1};
    EXPECT_EQ(true, containsDuplicate(question));

    question = {0};
    EXPECT_EQ(false, containsDuplicate(question));

    question = {1, 5, -2, -4, 0};
    EXPECT_EQ(false, containsDuplicate(question));

    question = {100000, -100000, 300000, 4100000, 0};
    EXPECT_EQ(false, containsDuplicate(question));

    question = {100000, 200000, 300000, 400000, 400000};
    EXPECT_EQ(true, containsDuplicate(question));

    question = {100000, 200000, 300000, 400000, 500000};
    EXPECT_EQ(false, containsDuplicate(question));
}