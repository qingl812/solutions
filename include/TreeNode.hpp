#pragma
#include <cmath>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

namespace zql {
/***
 * @brief 带头节点的二叉树
 * @details 头节点的 left 节点 为二叉树的 root
 * @author qingl
 * @date 2022_04_11
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}

    // 从一个表示完全二叉树的数组 转化为 二叉树
    // 如果某个节点为空 应赋值为 INT_MIN
    TreeNode(const std::vector<int>& tree) { this->operator=(tree); }
    TreeNode(std::initializer_list<int> list) { this->operator=(list); };

private:
    // 根据层次遍历构造二叉树
    TreeNode* buildTree(const std::vector<int>& tree, int i) {
        if (i >= tree.size() || tree[i] == INT_MIN) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(tree[i]);

        root->left = buildTree(tree, 2 * i + 1);
        root->right = buildTree(tree, 2 * i + 2);

        return root;
    }

public:
    TreeNode& operator=(const std::vector<int>& tree) {
        this->left = buildTree(tree, 0);
        this->right = nullptr;
        return *this;
    }
    TreeNode& operator=(std::initializer_list<int> list) {
        this->operator=(std::vector<int>(list));
        return *this;
    };

    // 计算二叉树深度,（不带头节点）
    static std::size_t GetTreeDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        auto left = GetTreeDepth(root->left);
        auto right = GetTreeDepth(root->right);

        return left >= right ? left + 1 : right + 1;
    }

    // 从链表转化为数组
    operator std::vector<int>() const {
        if (this->left == nullptr)
            return std::vector<int>();

        std::vector<int> ret;
        std::queue<TreeNode*> toVisit;
        auto depth = GetTreeDepth(this->left);
        // depth 层完全二叉树节点个数
        auto n = std::pow(2, depth) - 1;

        toVisit.push(this->left);
        for (std::size_t i = 0; i < n; i++) {
            auto node = toVisit.front();
            toVisit.pop();

            if (node != nullptr) {
                toVisit.push(node->left);
                toVisit.push(node->right);
                ret.push_back(node->val);
            } else {
                toVisit.push(nullptr);
                toVisit.push(nullptr);
                ret.push_back(INT_MIN);
            }
        }

        while (*(ret.end() - 1) == INT_MIN)
            ret.erase(ret.end() - 1);

        return ret;
    }
};

/***
 * @brief 判断两个 二叉树 或 数组 相等
 * @author qingl
 * @date 2022_04_11
 */
inline bool operator==(const TreeNode& left, const TreeNode& right) {
    return (std::vector<int>)left == (std::vector<int>)right;
}
inline bool operator==(const std::vector<int>& left, const TreeNode& right) {
    return (std::vector<int>)left == (std::vector<int>)right;
}
inline bool operator==(const TreeNode& left, const std::vector<int>& right) {
    return (std::vector<int>)left == (std::vector<int>)right;
}
/***
 * @brief 判断两个 二叉树 或 数组 不相等
 * @author qingl
 * @date 2022_04_11
 */
inline bool operator!=(const TreeNode& left, const TreeNode& right) {
    return (std::vector<int>)left != (std::vector<int>)right;
}
inline bool operator!=(const std::vector<int>& left, const TreeNode& right) {
    return (std::vector<int>)left != (std::vector<int>)right;
}
inline bool operator!=(const TreeNode& left, const std::vector<int>& right) {
    return (std::vector<int>)left != (std::vector<int>)right;
}

/***
 * @brief gtest 打印链表等
 * @author qingl
 * @date 2022_04_11
 */
inline std::ostream& operator<<(std::ostream& os, const TreeNode& tree) {
    auto nums = std::vector<int>(tree);
    std::string out = "{ ";
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == INT_MIN)
            out += "null";
        else
            out += std::to_string(nums[i]);
        if (i + 1 < nums.size())
            out += ", ";
    }
    out += " }";
    return os << out;
}
} // namespace zql
