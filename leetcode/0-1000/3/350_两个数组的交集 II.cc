#include "common.h"

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    vector<int> res;
    for (auto i : nums1) {
        m[i]++;
    }
    for (auto i : nums2) {
        if (m[i] > 0) {
            res.push_back(i);
            m[i]--;
        }
    }
    return res;
}

TEST(solution, intersect) {
    vector<int> question_a, question_b;
    vector<int> expected, answer;

    question_a = {1, 2, 2, 1};
    question_b = {2, 2};
    expected = {2, 2};
    answer = intersect(question_a, question_b);
    sort(answer.begin(), answer.end());
    EXPECT_EQ(expected, answer);

    question_a = {4, 9, 5};
    question_b = {9, 4, 9, 8, 4};
    expected = {4, 9};
    answer = intersect(question_a, question_b);
    sort(answer.begin(), answer.end());
    EXPECT_EQ(expected, answer);
}
