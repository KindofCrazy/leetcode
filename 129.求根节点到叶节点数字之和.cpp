/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;
        sum = sum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            ans += sum;
        }

        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end

