#include "common.h"

void reverseString(vector<char>& s) {
    auto left = s.begin(), right = s.end() - 1;
    while (left < right) {
        swap(*left++, *right--);
    }
}

TEST(solution, reverseString) {
    vector<char> problem, answer;

    problem = {'h', 'e', 'l', 'l', 'o'};
    answer = {'o', 'l', 'l', 'e', 'h'};
    reverseString(problem);
    EXPECT_EQ(answer, problem);

    problem = {'H', 'a', 'n', 'n', 'a', 'h'};
    answer = {'h', 'a', 'n', 'n', 'a', 'H'};
    reverseString(problem);
    EXPECT_EQ(answer, problem);

    problem = {'H', 'h'};
    answer = {'h', 'H'};
    reverseString(problem);
    EXPECT_EQ(answer, problem);

    problem = {'H'};
    answer = {'H'};
    reverseString(problem);
    EXPECT_EQ(answer, problem);
}