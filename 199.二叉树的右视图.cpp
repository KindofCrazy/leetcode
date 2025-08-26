/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* ptr = root;
        
        if (root == nullptr) return {};
        vector<int> ans;
        q.push(ptr);
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                ptr = q.front();
                q.pop();
                if (ptr->left != nullptr) q.push(ptr->left);
                if (ptr->right != nullptr) q.push(ptr->right);
                size--;
            }
            ans.push_back(ptr->val);
        }
        return ans;
    }
};
// @lc code=end

