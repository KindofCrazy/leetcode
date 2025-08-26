/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* ptr = root;
        while(ptr != nullptr || !stk.empty()) {
            while(ptr != nullptr) {
                stk.push(ptr);
                ptr = ptr->left;
            }

            ptr = stk.top();
            stk.pop();
            k--;
            if (k == 0) return ptr->val;
            ptr = ptr->right;
        }
        return -1;
    }
};
// @lc code=end

