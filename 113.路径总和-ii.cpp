/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};

        auto left = pathSum(root->left, targetSum - root->val), right = pathSum(root->right, targetSum - root->val);

        vector<vector<int>> ret;
        if (!root->left && !root->right && root->val == targetSum) {
            ret.push_back({root->val});
        }

        for (auto path: left) {
            path.insert(path.begin(), root->val);  
            ret.emplace_back(path);

        }
        for (auto path: right) {
            path.insert(path.begin(), root->val);
            ret.emplace_back(path);
        }

        return ret;
    }
};
// @lc code=end

