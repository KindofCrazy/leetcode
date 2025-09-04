/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    void dfs(TreeNode* root, long long & ans, int rootVal) {
        if (root == nullptr) return;
        if (root->val > rootVal) {
            ans = min(ans, (long long) root->val);
        }

        dfs(root->left, ans, rootVal);
        dfs(root->right, ans, rootVal);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long ans = LONG_MAX;
        dfs(root, ans, root->val);
        return ans == LONG_MAX? -1: ans;
    }
};
// @lc code=end

