/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};

        vector<string> left = binaryTreePaths(root->left), right = binaryTreePaths(root->right);

        vector<string> ret;
        if (left.empty() && right.empty()) ret.push_back(to_string(root->val));

        for (string s: left) {
            ret.push_back(to_string(root->val) + "->" + s);
        }
        for (string s: right) {
            ret.push_back(to_string(root->val) + "->" + s);
        }

        return ret;
    }
};
// @lc code=end

