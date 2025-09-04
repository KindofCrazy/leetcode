/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
        if (root == nullptr) return {INT_MAX, INT_MIN};
        pair<int, int> p1 = dfs(root->left), p2 = dfs(root->right);
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val, root->val};
        }

        int mi = min(p1.first, p2.first), mx = max(p1.second, p2.second);

        int diff = max(abs(root->val - mi), abs(root->val - mx));
        ans = max(ans, diff);

        return {min(root->val, mi), max(root->val, mx)};
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

