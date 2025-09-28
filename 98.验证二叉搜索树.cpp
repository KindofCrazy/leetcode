/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBSTHelper(TreeNode* root, long long lower, long long upper) {
        if (!root) return true;
        if (root->val >= upper || root->val <= lower) return false;

        return isValidBSTHelper(root->left, lower, root->val) && isValidBSTHelper(root->right, root->val, upper);
    }
};
// @lc code=end

