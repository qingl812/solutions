#include "common.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* buildTree(const std::vector<int>& tree, int i) {
    if (i >= tree.size() || tree[i] == INT_MIN) {
        return nullptr;
    }
    Node* root = new Node(tree[i]);

    root->left = buildTree(tree, 2 * i + 1);
    root->right = buildTree(tree, 2 * i + 2);

    return root;
}


Node* connect(Node* root) {
    if (!root)
        return nullptr;
    auto node = root;
    while (node->left) {
        for (auto i = node; i; i = i->next) {
            i->left->next = i->right;
            i->right->next = i->next ? i->next->left : nullptr;
        }
        node = node->left;
    }
    return root;
}

TEST(solution, connect) {
    vector<int> question = {1, 2, 3, 4, 5, 6, 7};
    vector<int> expected = {1, -1, 2, 3, -1, 4, 5, 6, 7, -1};
    Node* question_root = buildTree(question, 0);
    Node* answer_root = connect(question_root);
    vector<int> answer;

    Node* next = answer_root;
    while (next) {
        auto node = next;
        next = next->left;

        while (node) {
            answer.push_back(node->val);
            node = node->next;
        }
        answer.push_back(-1);
    }

    EXPECT_EQ(expected, answer);
}