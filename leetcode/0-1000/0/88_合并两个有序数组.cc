#include "common.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos_a = m - 1, pos_b = n - 1;
    int pos_ans = m + n - 1;
    while (pos_a >= 0 && pos_b >= 0) {
        if (nums1[pos_a] > nums2[pos_b]) {
            nums1[pos_ans--] = nums1[pos_a--];
        } else {
            nums1[pos_ans--] = nums2[pos_b--];
        }
    }
    while (pos_b >= 0) {
        nums1[pos_ans--] = nums2[pos_b--];
    }
}

TEST(solution, merge) {
    vector<int> question_a;
    vector<int> question_b;
    vector<int> expected;

    question_a = {1, 2, 3, 0, 0, 0};
    question_b = {2, 5, 6};
    expected = {1, 2, 2, 3, 5, 6};
    merge(question_a, 3, question_b, 3);
    EXPECT_EQ(expected, question_a);

    question_a = {1};
    question_b = {};
    expected = {1};
    merge(question_a, 1, question_b, 0);
    EXPECT_EQ(expected, question_a);

    question_a = {0};
    question_b = {1};
    expected = {1};
    merge(question_a, 0, question_b, 1);
    EXPECT_EQ(expected, question_a);
}