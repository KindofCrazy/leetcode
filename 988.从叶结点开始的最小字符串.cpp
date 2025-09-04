/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
    string s = "";
    string ans = "";

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        char c = (char) (root->val + 'a');
        s = c + s;
        if (root->left == nullptr && root->right == nullptr) {
            if (ans == "") {
                ans = s;
            } else {
                ans = min(ans, s);
            }
        }

        dfs(root->left);
        dfs(root->right);

        s = s.substr(1, s.size() - 1);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

