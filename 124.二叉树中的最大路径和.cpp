/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = dfs(root->left), right = dfs(root->right);
        int sum = root->val, ret = root->val;
        ret = max(ret, root->val + left);
        ret = max(ret, root->val + right);
        sum = max(ret, root->val + left + right);

        ans = max(ans, sum);

        return ret;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

