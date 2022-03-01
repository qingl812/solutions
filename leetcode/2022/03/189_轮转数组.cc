#include "common.h"

void rotate(vector<int> nums, int k) {}

TEST(solution, rotate) {
    vector<int> problem = {1, 2, 3, 4, 5, 6, 7};
    vector<int> answer = {5, 6, 7, 1, 2, 3, 4};
    rotate(problem, 3);
    EXPECT_EQ(answer, problem);

    problem = {-1, -100, 3, 99};
    answer = {3, 99, -1, -100};
    rotate(problem, 2);
    EXPECT_EQ(answer, problem);
}