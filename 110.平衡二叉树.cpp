/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool ans = true;

    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }

    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = height(root->left), right = height(root->right);
        if (abs(left - right) > 1) {
            ans = false;
        }

        return max(left, right) + 1;
    }
};
// @lc code=end

