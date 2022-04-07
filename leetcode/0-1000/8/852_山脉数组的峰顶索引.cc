#include "common.h"

int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

TEST(solution, peakIndexInMountainArray) {
    vector<int> question;

    question = {0, 1, 0};
    EXPECT_EQ(1, peakIndexInMountainArray(question));

    question = {0, 2, 1, 0};
    EXPECT_EQ(1, peakIndexInMountainArray(question));

    question = {0, 10, 5, 2};
    EXPECT_EQ(1, peakIndexInMountainArray(question));

    question = {3, 4, 5, 1};
    EXPECT_EQ(2, peakIndexInMountainArray(question));

    question = {18, 29, 38, 59, 98, 100, 99, 98, 90};
    EXPECT_EQ(5, peakIndexInMountainArray(question));
}