/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    vector<int> arr;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root);

        unordered_set<int> s;
        for (int n: arr) {
            if (s.count(k-n)) return true;
            s.insert(n);
        }
        return false;
    }
};
// @lc code=end

