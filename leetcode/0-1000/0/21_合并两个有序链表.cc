#include "common.h"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = new ListNode();
    ListNode* node = ans;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            node->next = list1;
            list1 = list1->next;
        } else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }
    node->next = list1 ? list1 : list2;
    return ans->next;
}

TEST(solution, mergeTwoLists) {
    ListNode question_a;
    ListNode question_b;
    ListNode expected;
    ListNode answer;

    question_a = {1, 2, 4};
    question_b = {1, 3, 4};
    expected = {1, 1, 2, 3, 4, 4};
    answer.next = mergeTwoLists(question_a.next, question_b.next);
    EXPECT_EQ(expected, answer);

    question_a = {};
    question_b = {};
    expected = {};
    answer.next = mergeTwoLists(question_a.next, question_b.next);
    EXPECT_EQ(expected, answer);

    question_a = {};
    question_b = {0};
    expected = {0};
    answer.next = mergeTwoLists(question_a.next, question_b.next);
    EXPECT_EQ(expected, answer);
}