/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 *
 * [2265] 统计值等于子树平均值的节点数
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

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        pair<int, int> left = dfs(root->left), right = dfs(root->right);
        int sum = left.first + right.first + root->val;
        int num = left.second + right.second + 1;
        if (root->val == sum / num) {
            ans++;
        }

        return {sum, num};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

