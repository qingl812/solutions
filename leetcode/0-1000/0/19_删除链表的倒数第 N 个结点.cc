#include "common.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *slow, *fast;
    slow = fast = dummy;
    while (n--) {
        fast = fast->next;
    }
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    auto ans = dummy->next;
    return ans;
}

ListNode* removeNthFromEnd_2(ListNode* head, int n) {
    stack<ListNode*> nodes;
    auto p = head;
    while (p != nullptr) {
        nodes.push(p);
        p = p->next;
    }
    while (n--) {
        if (nodes.empty())
            return head;
        nodes.pop();
    }
    // 此时 nodes.top() 为倒数第 n+1 个节点
    if (nodes.empty())
        return head->next;
    auto a = nodes.top();
    if (a->next != nullptr)
        a->next = a->next->next;
    else
        a->next = nullptr;
    return head;
}

TEST(solution, removeNthFromEnd) {
    ListNode actual;
    ListNode expected;

    actual = {1, 2, 3, 4, 5};
    expected = {1, 2, 3, 5};
    actual.next = removeNthFromEnd(actual.next, 2);
    EXPECT_EQ(expected, actual);

    actual = {1};
    expected = {};
    actual.next = removeNthFromEnd(actual.next, 1);
    EXPECT_EQ(expected, actual);

    actual = {1, 2};
    expected = {1};
    actual.next = removeNthFromEnd(actual.next, 1);
    EXPECT_EQ(expected, actual);

    actual = {1, 2};
    expected = {2};
    actual.next = removeNthFromEnd(actual.next, 2);
    EXPECT_EQ(expected, actual);
}

TEST(solution, removeNthFromEnd_2) {
    ListNode actual;
    ListNode expected;

    actual = {1, 2, 3, 4, 5};
    expected = {1, 2, 3, 5};
    actual.next = removeNthFromEnd_2(actual.next, 2);
    EXPECT_EQ(expected, actual);

    actual = {1};
    expected = {};
    actual.next = removeNthFromEnd_2(actual.next, 1);
    EXPECT_EQ(expected, actual);

    actual = {1, 2};
    expected = {1};
    actual.next = removeNthFromEnd_2(actual.next, 1);
    EXPECT_EQ(expected, actual);

    actual = {1, 2};
    expected = {2};
    actual.next = removeNthFromEnd_2(actual.next, 2);
    EXPECT_EQ(expected, actual);
}