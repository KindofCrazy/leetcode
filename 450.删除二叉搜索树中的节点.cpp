/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (root->left == nullptr) return root->right;

        TreeNode* node = root->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        node->right = root->right;

        return root->left;
    }
};
// @lc code=end

