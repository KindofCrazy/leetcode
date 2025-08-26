/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> layer;
            while(size--) {
                TreeNode* ptr = q.front();
                q.pop();
                layer.push_back(ptr->val);
                if (ptr->left != nullptr) q.push(ptr->left);
                if (ptr->right != nullptr) q.push(ptr->right);
            }
            ans.emplace_back(layer);
        }
        return ans;
    }
};
// @lc code=end

