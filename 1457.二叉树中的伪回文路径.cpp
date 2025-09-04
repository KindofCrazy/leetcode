/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
    vector<int> cnt;

    bool isPalindrom(vector<int> c) {
        int odd = 0;
        for (int n: c) {
            odd += (n % 2);
        }
        return odd <= 1;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        cnt[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            ans += isPalindrom(cnt);
        }
        dfs(root->left);
        dfs(root->right);

        cnt[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        cnt.resize(10, 0);
        dfs(root);
        return ans;
    }
};
// @lc code=end

