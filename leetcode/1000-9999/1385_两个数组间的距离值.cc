#include "common.h"

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int arr2_n = arr2.size();
    int ans = arr1.size();
    for (auto i : arr1) {
        // arr2 >= i-d && arr2 <= i+d
        int left = 0;
        int right = arr2_n - 1;
        // 找到第一个大于等于 i-d 的数
        int t = i - d;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr2[mid] < t) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (arr2[left] >= t && arr2[left] <= i + d)
            ans--;
    }
    return ans;
}

TEST(solution, findTheDistanceValue) {
    vector<int> question_a, question_b;

    question_a = {4, 5, 8};
    question_b = {10, 9, 1, 8};
    EXPECT_EQ(2, findTheDistanceValue(question_a, question_b, 2));

    question_a = {1, 4, 2, 3};
    question_b = {-4, -3, 6, 10, 20, 30};
    EXPECT_EQ(2, findTheDistanceValue(question_a, question_b, 3));

    question_a = {2, 1, 100, 3};
    question_b = {-5, -2, 10, -3, 7};
    EXPECT_EQ(1, findTheDistanceValue(question_a, question_b, 6));
}