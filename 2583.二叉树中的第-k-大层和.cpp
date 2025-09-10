/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        vector<long long> sum;

        q.push(root);
        while (!q.empty()) {
            long long level = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                level += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            sum.push_back(level);
        }

        sort(sum.begin(), sum.end());
        if (sum.size() < k) return -1;
        return sum[sum.size() - k];
    }
};
// @lc code=end

