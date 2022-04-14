#include "common.h"

bool hasCycle(ListNode* head) {
    if (!head)
        return false;
    auto slow = head, fast = head->next;
    while (slow != fast && fast != nullptr) {
        slow = slow->next;
        fast = fast->next ? fast->next->next : nullptr;
    }
    return fast != nullptr;
}

TEST(solution, hasCycle) {
    ListNode question;

    question = {3, 2, 0, -4};
    question.next->next->next->next->next = question.next->next;
    EXPECT_EQ(true, hasCycle(question.next));

    question = {1, 2};
    question.next->next->next = question.next;
    EXPECT_EQ(true, hasCycle(question.next));

    question = {1};
    EXPECT_EQ(false, hasCycle(question.next));

    question = {};
    EXPECT_EQ(false, hasCycle(question.next));
}
