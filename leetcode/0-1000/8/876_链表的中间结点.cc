#include "common.h"

ListNode* middleNode(ListNode* head) {
    ListNode *left, *right;
    left = right = head;
    while (right->next != nullptr) {
        right = right->next;
        left = left->next;
        if (right->next != nullptr) {
            right = right->next;
        }
    }
    return left;
}

TEST(solution, middleNode) {
    ListNode actual, expected;

    actual = {1, 2, 3, 4, 5};
    expected = {3, 4, 5};
    actual.next = middleNode(actual.next);
    EXPECT_EQ(expected, actual);

    actual = {1, 2, 3, 4, 5, 6};
    expected = {4, 5, 6};
    actual.next = middleNode(actual.next);
    EXPECT_EQ(expected, actual);
}