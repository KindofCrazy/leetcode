/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 *
 * [1339] 分裂二叉树的最大乘积
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
    int totalSum = 0;
    long long ans = 0;
    void total(TreeNode* root) {
        if (root == nullptr) return;
        totalSum += root->val;
        total(root->left);
        total(root->right);
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        int sum = root->val + left + right;

        if (sum != 0) ans = max(ans, ((long long)(totalSum - sum) * sum));
        return sum;
    }

    int maxProduct(TreeNode* root) {
        total(root);
        dfs(root);
        return ans % ((int) pow(10, 9) + 7);
    }
};
// @lc code=end

