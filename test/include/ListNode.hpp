#pragma
#include <vector>
#include <iostream>
#include <string>

namespace zql {
// 带头节点的链表
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    // 从数组转化为链表
    ListNode(const std::vector<int>& array) { this->operator=(array); }
    ListNode(std::initializer_list<int> list) { this->operator=(list); };

    ListNode& operator=(const std::vector<int>& array) {
        this->next = nullptr;
        ListNode* p = this;
        for (auto i : array) {
            p->next = new ListNode(i);
            p = p->next;
        }
        return *this;
    }
    ListNode& operator=(std::initializer_list<int> list) {
        this->operator=(std::vector<int>(list));
        return *this;
    };

    // 从链表转化为数组
    operator std::vector<int>() const {
        std::vector<int> ret;
        auto p = this->next;
        while (p != nullptr) {
            ret.push_back(p->val);
            p = p->next;
        }
        return ret;
    }
};

//判断两个 链表 或 数组 相等
bool operator==(const ListNode& left, const ListNode& right) {
    return (std::vector<int>)left == (std::vector<int>)right;
}
bool operator==(const std::vector<int>& left, const ListNode& right) {
    return (std::vector<int>)left == (std::vector<int>)right;
}
bool operator==(const ListNode& left, const std::vector<int>& right) {
    return (std::vector<int>)left == (std::vector<int>)right;
}
//判断两个 链表 或 数组 不相等
bool operator!=(const ListNode& left, const ListNode& right) {
    return (std::vector<int>)left != (std::vector<int>)right;
}
bool operator!=(const std::vector<int>& left, const ListNode& right) {
    return (std::vector<int>)left != (std::vector<int>)right;
}
bool operator!=(const ListNode& left, const std::vector<int>& right) {
    return (std::vector<int>)left != (std::vector<int>)right;
}

// gtest 打印链表
std::ostream& operator<<(std::ostream& os, const ListNode& head) {
    auto p = head.next;
    std::string out = "{ ";
    while (p != nullptr) {
        out += std::to_string(p->val);
        if (p->next != nullptr)
            out += ", ";
        p = p->next;
    }
    out += " }";
    return os << out;
}
} // namespace zql
