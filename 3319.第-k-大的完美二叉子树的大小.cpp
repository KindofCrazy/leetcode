/*
 * @lc app=leetcode.cn id=3319 lang=cpp
 *
 * [3319] 第 K 大的完美二叉子树的大小
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
    vector<int> nums;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == -1 || right == -1) return -1;

        if (left == right) {
            nums.push_back(left + right + 1);
            return left + right + 1;
        }

        return -1;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(nums.begin(), nums.end());
        if (k > nums.size()) return -1;
        return nums[nums.size() - k];
    }
};
// @lc code=end

