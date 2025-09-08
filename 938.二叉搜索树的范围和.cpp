/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;
        int left = 0, right = 0;
        if (low < root->val) {
            left = rangeSumBST(root->left, low, high);
        }
        if (high > root->val) {
            right = rangeSumBST(root->right, low, high);
        }
        if (root->val >= low && root->val <= high) {
            return root->val + left + right;
        }

        return left + right;
    }
};
// @lc code=end

