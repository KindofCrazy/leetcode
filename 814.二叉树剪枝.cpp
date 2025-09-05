/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    bool dfs(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = dfs(root->left), right = dfs(root->right);
        if (left) root->left = nullptr;
        if (right) root->right = nullptr;

        return !root->val && left && right;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (dfs(root)) return nullptr;
        return root;
    }
};
// @lc code=end

