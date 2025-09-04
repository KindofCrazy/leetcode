/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    void dfs(TreeNode* root, int maxNum) {
        if (root == nullptr) return;
        if (root->val >= maxNum) {
            ans++;
        }

        maxNum = max(maxNum, root->val);
        dfs(root->left, maxNum);
        dfs(root->right, maxNum);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return ans;
    }
};
// @lc code=end

