/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int ans = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = dfs(root->left), right = dfs(root->right);
        int len = 0, ret = 0;
        if (root->left != nullptr && root->val == root->left->val) {
            len += (left + 1);
            ret = max(left+1, ret);
        }
        if (root->right != nullptr && root->val == root->right->val) {
            len += (right + 1);
            ret = max(right+1, ret);
        }

        ans = max(ans, len);

        return ret;
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

