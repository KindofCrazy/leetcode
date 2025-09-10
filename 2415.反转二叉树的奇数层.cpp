/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) return 0;

        vector<TreeNode*> q;

        int level = 0;
        q.push_back(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> l;
            for (int i = 0; i < sz; i++) {
                auto node = q[i];
                if (level % 2 == 1 && i < sz / 2) {
                    swap(node->val, q[sz-1-i]->val);
                }
                

                if (node->left) l.push_back(node->left);
                if (node->right) l.push_back(node->right);
            }
            q = l;
            level++;
        }

        return root;
    }
};
// @lc code=end

