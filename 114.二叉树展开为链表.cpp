/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root, *pre = new TreeNode(0, nullptr, root);
        while(node != nullptr || !stk.empty()) {
            if (node == nullptr) {
                node = stk.top();
                stk.pop();
            }

            if (node->right != nullptr) stk.push(node->right);
            pre->right = node;
            pre->left = nullptr;
            pre = node;
            node = node->left;
        }
    }
};
// @lc code=end

