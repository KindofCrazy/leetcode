/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int ret = 0;
    void rootSum(TreeNode* root, long targetSum) {
        if (root == nullptr) {
            return;
        }
        if (root->val == targetSum) {
            ret += 1;
        }

        rootSum(root->left, targetSum - root->val);
        rootSum(root->right, targetSum - root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return ret;
        rootSum(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ret;
    }
};
// @lc code=end

