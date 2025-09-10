/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> occ(2, false);
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                    if (occ[0] && node->left->val == y) return true;
                    if (occ[1] && node->left->val == x) return true;
                }
                if (node->right) {
                    q.push(node->right);
                    if (occ[0] && node->right->val == y) return true;
                    if (occ[1] && node->right->val == x) return true;
                }

                if (node->left) {
                    occ[0] = occ[0] || node->left->val == x;
                    occ[1] = occ[1] || node->left->val == y;
                }
                if (node->right) {
                    occ[0] = occ[0] || node->right->val == x;
                    occ[1] = occ[1] || node->right->val == y;
                }
            }
        }

        return false;
    }
};
// @lc code=end

