/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode* ans;

    void inOrder(TreeNode* root, TreeNode*& pre) {
        if (root == nullptr) return;
        inOrder(root->left, pre);

        root->left = nullptr;
        if (pre != nullptr) {
            pre->right = root;
        } else {
            ans = root;
        }
        pre = root;
        inOrder(root->right, pre);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        inOrder(root, pre);
        return ans;
    }
};
// @lc code=end

