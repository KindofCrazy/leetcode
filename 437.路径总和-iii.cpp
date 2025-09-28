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
    int ans = 0;
    
    void rootSum(TreeNode* root, long long target) {
        if (!root) return;
        if (root->val == target) ans++;

        rootSum(root->left, target - root->val);
        rootSum(root->right, target - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        rootSum(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};
// @lc code=end

