#include "common.h"

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1)
        return root2;
    else if (!root2)
        return root1;

    root1->val += root2->val;
    queue<TreeNode*> queue_a;
    queue<TreeNode*> queue_b;
    queue_a.push(root1);
    queue_b.push(root2);

    while (!queue_b.empty()) {
        auto node_a = queue_a.front();
        queue_a.pop();
        auto node_b = queue_b.front();
        queue_b.pop();

        if (node_b->left) {
            if (node_a->left) {
                node_a->left->val += node_b->left->val;
                queue_a.push(node_a->left);
                queue_b.push(node_b->left);
            } else {
                node_a->left = node_b->left;
            }
        }

        if (node_b->right) {
            if (node_a->right) {
                node_a->right->val += node_b->right->val;
                queue_a.push(node_a->right);
                queue_b.push(node_b->right);
            } else {
                node_a->right = node_b->right;
            }
        }
    }

    return root1;
}

TEST(solution, mergeTrees) {
    TreeNode question_a;
    TreeNode question_b;
    TreeNode expected;
    TreeNode answer;

    question_a = {1, 3, 2, 5};
    question_b = {2, 1, 3, INT_MIN, 4, INT_MIN, 7};
    expected = {3, 4, 5, 5, 4, INT_MIN, 7};
    answer.left = mergeTrees(question_a.left, question_b.left);
    EXPECT_EQ(expected, answer);

    question_a = {1};
    question_b = {1, 2};
    expected = {2, 2};
    answer.left = mergeTrees(question_a.left, question_b.left);
    EXPECT_EQ(expected, answer);

    question_a = {};
    question_b = {};
    expected = {};
    answer.left = mergeTrees(question_a.left, question_b.left);
    EXPECT_EQ(expected, answer);

    question_a = {};
    question_b = {2};
    expected = {2};
    answer.left = mergeTrees(question_a.left, question_b.left);
    EXPECT_EQ(expected, answer);
}