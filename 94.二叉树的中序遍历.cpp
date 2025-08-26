/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;

        TreeNode* ptr = root;
        while(ptr != nullptr || !stk.empty()) {
            while(ptr != nullptr) {
                stk.push(ptr);
                ptr = ptr->left;
            }
            ptr = stk.top();
            stk.pop();
            ans.push_back(ptr->val);
            ptr = ptr->right;
        }
        return ans;
    }
};
// @lc code=end

