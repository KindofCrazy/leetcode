/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> ans;
    void inOrder(TreeNode* root) {
        if (!root) return;

        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};
// @lc code=end

