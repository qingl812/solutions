#include "common.h"

int findKthPositive(vector<int>& arr, int k) {
    if (arr[0] > k) {
        return k;
    }

    int left = 0, right = (int)arr.size();
    while (left < right) {
        auto mid = left + (right - left) / 2;
        if (arr[mid] - mid - 1 >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return k - (arr[left - 1] - (left - 1) - 1) + arr[left - 1];
}

TEST(solution, findKthPositive) {
    vector<int> question;

    // question = {2};
    // EXPECT_EQ(1, findKthPositive(question, 1));

    question = {1};
    EXPECT_EQ(2, findKthPositive(question, 1));

    question = {1, 2, 3, 5};
    EXPECT_EQ(4, findKthPositive(question, 1));

    //     question = {2, 3, 4, 7, 11};
    //     EXPECT_EQ(9, findKthPositive(question, 5));

    //     question = {1, 2, 3, 4};
    //     EXPECT_EQ(6, findKthPositive(question, 2));
}
