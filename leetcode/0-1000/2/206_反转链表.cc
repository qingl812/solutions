#include "common.h"

ListNode* reverseList(ListNode* head) {
    if (!head)
        return nullptr;

    auto cur = head, next = cur->next;
    cur->next = nullptr;
    while (next) {
        auto t = next->next;
        next->next = cur;
        cur = next;
        next = t;
    }

    return cur;
}

// ListNode* reverseList(ListNode* head) {
//     if (head && head->next) {
//         auto ret = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return ret;
//     } else
//         return head;
// }

TEST(solution, reverseList) {
    ListNode question;
    ListNode expected;
    ListNode answer;

    question = {1, 2, 3, 4, 5};
    expected = {5, 4, 3, 2, 1};
    answer.next = reverseList(question.next);
    EXPECT_EQ(expected, answer);

    question = {1, 2};
    expected = {2, 1};
    answer.next = reverseList(question.next);
    EXPECT_EQ(expected, answer);

    question = {};
    expected = {};
    answer.next = reverseList(question.next);
    EXPECT_EQ(expected, answer);
}