/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    void inOrder(TreeNode* root, int& pre, int& ans) {
        if (root == nullptr) return;
        inOrder(root->left, pre, ans);
        if (pre != -1) {
            ans = min(ans, abs(root->val - pre));
        }

        pre = root->val;
        inOrder(root->right, pre, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int pre = -1, ans = INT_MAX;
        inOrder(root, pre, ans);
        return ans;
    }
};
// @lc code=end

