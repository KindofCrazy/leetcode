/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int dfs(TreeNode* root, bool isGreen, bool isRed) {
        if (root == nullptr) return 0;
        int left = 0, right = 0;
        if (root->val % 2 == 0) {
            left = dfs(root->left, true, isGreen);
            right = dfs(root->right, true, isGreen);
        } else {
            left = dfs(root->left, false, isGreen);
            right = dfs(root->right, false, isGreen);
        }

        return (isRed? root->val: 0) + left + right;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, false, false);
    }
};
// @lc code=end

