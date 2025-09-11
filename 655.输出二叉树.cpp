/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
    int height(TreeNode* root) {
        if (!root) return -1;
        return max(height(root->left), height(root->right)) + 1;
    }

    void place(TreeNode* root, int row, int col, int h, vector<vector<string>>& matrix) {
        if (!root) return;
        matrix[row][col] = to_string(root->val);
        place(root->left, row+1, col-pow(2, h-row-1), h, matrix);
        place(root->right, row+1, col+pow(2, h-row-1), h, matrix);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);

        vector<vector<string>> ans(h+1, vector<string>(pow(2, h+1)-1, ""));
        place(root, 0, (pow(2, h+1)-1)/2, h, ans);
        return ans;
    }
};
// @lc code=end

