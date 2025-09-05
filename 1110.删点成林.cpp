/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    unordered_set<int> del;
    vector<TreeNode*> roots;

    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        bool deleted = del.count(root->val);
        TreeNode* left = dfs(root->left), *right = dfs(root->right);

        if (deleted) {
            if (left) roots.push_back(root->left);
            if (right) roots.push_back(root->right);
            return nullptr;
        } 
        
        root->left = left;
        root->right = right;
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int n: to_delete) {
            del.insert(n);
        }

        root = dfs(root);
        if (root) roots.push_back(root);
        return roots;
    }
};
// @lc code=end

