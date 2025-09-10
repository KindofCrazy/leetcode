/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) return false;

        queue<TreeNode*> q;
        bool isOdd = false;

        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int pre = isOdd? INT_MAX: INT_MIN;
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                if (isOdd) {
                    if (node->val % 2 == 1) return false;
                    if (node->val >= pre) return false;
                } else {
                    if (node->val % 2 == 0) return false;
                    if (node->val <= pre) return false;
                }

                pre = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            isOdd = !isOdd;
        }

        return true;
    }
};
// @lc code=end

