/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void inOrder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return;
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }

    pair<int, int> find(vector<int>& arr) {
        int n = arr.size();
        int x = -1, y = -1;
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) {
                if (x == -1) x = i;
                y = i+1;
            }
        }

        return {arr[x], arr[y]};
    }

    void recover(TreeNode* root, int x, int y) {
        if (root == nullptr) return;
        if (root->val == x) {
            root->val = y;
        } else if (root->val == y) {
            root->val = x;
        }

        recover(root->left, x, y);
        recover(root->right, x, y);
    }

    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inOrder(root, arr);

        auto p = find(arr);
        recover(root, p.first, p.second);
    }
};
// @lc code=end

