#include "common.h"

ListNode* deleteDuplicates(ListNode* head) {
    ListNode root;
    root.next = head;
    auto node = &root;
    while (node->next) {
        if (node->next->val == node->val) {
            auto to_del = node->next;
            node->next = node->next->next;
            delete to_del;
        } else
            node = node->next;
    }
    return root.next;
}

TEST(solution, deleteDuplicates) {
    ListNode question;
    ListNode expected;
    ListNode answer;

    question = {1, 1, 2};
    expected = {1, 2};
    answer.next = deleteDuplicates(question.next);
    EXPECT_EQ(expected, answer);

    question = {1, 1, 2, 3, 3};
    expected = {1, 2, 3};
    answer.next = deleteDuplicates(question.next);
    EXPECT_EQ(expected, answer);

    question = {1};
    expected = {1};
    answer.next = deleteDuplicates(question.next);
    EXPECT_EQ(expected, answer);

    question = {};
    expected = {};
    answer.next = deleteDuplicates(question.next);
    EXPECT_EQ(expected, answer);

    question = {1, 2};
    expected = {1, 2};
    answer.next = deleteDuplicates(question.next);
    EXPECT_EQ(expected, answer);

    question = {1, 1};
    expected = {1};
    answer.next = deleteDuplicates(question.next);
    EXPECT_EQ(expected, answer);
}
