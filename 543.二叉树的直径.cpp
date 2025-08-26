/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        maxLength(root, ans); 
        return ans;
    }

    int maxLength(TreeNode* root, int& ans) {
        if (root == nullptr) return -1;
        int leftLength = maxLength(root->left, ans) + 1;
        int rightLength = maxLength(root->right, ans) + 1;
        ans = max(ans, leftLength+rightLength);
        return max(leftLength, rightLength);
    }
};
// @lc code=end

