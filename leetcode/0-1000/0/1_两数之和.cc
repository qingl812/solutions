#include "common.h"

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        if (hash.find(target - nums[i]) != hash.end()) {
            return vector<int>{i, hash[target - nums[i]]};
        }
        hash[nums[i]] = i;
    }

    return vector<int>{};
}

TEST(solution, twoSum) {
    vector<int> question;
    vector<int> expected;
    vector<int> answer;

    question = {2, 7, 11, 15};
    expected = {0, 1};
    answer = twoSum(question, 9);
    std::sort(answer.begin(), answer.end());
    EXPECT_EQ(expected, answer);

    question = {3, 2, 4};
    expected = {1, 2};
    answer = twoSum(question, 6);
    std::sort(answer.begin(), answer.end());
    EXPECT_EQ(expected, answer);

    question = {3, 3};
    expected = {0, 1};
    answer = twoSum(question, 6);
    std::sort(answer.begin(), answer.end());
    EXPECT_EQ(expected, answer);
}