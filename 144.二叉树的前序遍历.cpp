/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> pre;
    void preOrder(TreeNode* root) {
        if (root == nullptr) return;
        pre.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return pre;
    }
};
// @lc code=end

