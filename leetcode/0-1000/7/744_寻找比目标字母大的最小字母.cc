#include "common.h"

char nextGreatestLetter(vector<char>& letters, char target) {
    if (target >= letters.back())
        return letters[0];
    int left = 0, right = letters.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (letters[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return letters[left];
}

TEST(solution, nextGreatestLetter) {
    vector<char> question;

    question = {'c', 'f', 'j'};
    EXPECT_EQ('c', nextGreatestLetter(question, 'a'));

    question = {'c', 'f', 'j'};
    EXPECT_EQ('f', nextGreatestLetter(question, 'c'));

    question = {'c', 'f', 'j'};
    EXPECT_EQ('f', nextGreatestLetter(question, 'd'));

    question = {'c', 'f', 'j'};
    EXPECT_EQ('c', nextGreatestLetter(question, 'j'));
}