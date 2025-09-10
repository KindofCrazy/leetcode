/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        bool isLeft = true;
        q.push(root);
        while (!q.empty()) {
            deque<int> level;
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();

                if (isLeft) {
                    level.push_back(node->val);
                } else {
                    level.push_front(node->val);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            isLeft = !isLeft;
            ans.emplace_back(vector<int>{level.begin(), level.end()});
        }

        return ans;
    }
};
// @lc code=end

