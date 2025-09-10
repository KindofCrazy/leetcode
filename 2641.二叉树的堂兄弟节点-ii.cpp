/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        vector<TreeNode*> q = {root};
        root->val = 0;

        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            for (int i = 0; i < sz; i++) {
                auto node = q[i];
                int childSum = (node->left? node->left->val: 0) + (node->right? node->right->val: 0);
                sum += childSum;
            }

            vector<TreeNode*> level;
            for (int i = 0; i < sz; i++) {
                auto node = q[i];
                int childSum = (node->left? node->left->val: 0) + (node->right? node->right->val: 0);

                if (node->left) {
                    node->left->val = sum - childSum;
                    level.push_back(node->left);
                }

                if (node->right) {
                    node->right->val = sum - childSum;
                    level.push_back(node->right);
                }
            }

            q = move(level);
        }
        return root;
    }
};
// @lc code=end

