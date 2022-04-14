#include "common.h"

ListNode* removeElements(ListNode* head, int val) {
    ListNode root;
    root.next = head;
    auto node = &root;
    while (node->next) {
        if (node->next->val == val) {
            auto to_del = node->next;
            node->next = node->next->next;
            delete to_del;
        } else
            node = node->next;
    }
    return root.next;
}

TEST(solution, removeElements) {
    ListNode question;
    ListNode expected;
    ListNode answer;

    question = {1, 2, 6, 3, 4, 5, 6};
    expected = {1, 2, 3, 4, 5};
    answer.next = removeElements(question.next, 6);
    EXPECT_EQ(answer, expected);

    question = {};
    expected = {};
    answer.next = removeElements(question.next, 1);
    EXPECT_EQ(answer, expected);

    question = {7, 7, 7, 7};
    expected = {};
    answer.next = removeElements(question.next, 7);
    EXPECT_EQ(answer, expected);
}
